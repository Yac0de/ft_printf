/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_string_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:55:33 by ymeziane          #+#    #+#             */
/*   Updated: 2023/10/31 18:55:33 by ymeziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	write_string(char *c, t_flags flags)
{
	int				count;
	unsigned int	len;

	count = 0;
	if (!ft_strncmp(c, "(null)", ft_strlen("(null)"))
		&& flags.precision > -1 && flags.precision < (int)ft_strlen("(null)"))
		return (0);
	len = ft_strlen(c);
	if (flags.dot && flags.precision == -1)
		return (0);
	if (flags.precision == -1 || flags.precision > (int)len)
	{
		ft_putstr_fd(c, 1);
		return (len);
	}
	while (flags.precision--)
	{
		write(1, c, 1);
		count++;
		c++;
	}
	return (count);
}

static int	write_padding(int width, int len_c, char padding_char)
{
	int	count;

	count = 0;
	while (width > len_c)
	{
		write(1, &padding_char, 1);
		count++;
		width--;
	}
	return (count);
}

static int	write_string_with_flags(char *c, t_flags flags)
{
	int		count;
	size_t	len_c;

	count = 0;
	len_c = ft_strlen(c);
	if (flags.dot)
	{
		if (!ft_strncmp(c, "(null)", 6) && flags.precision < 6)
			len_c = 0;
		if (flags.precision >= 0 && flags.precision < (int)len_c)
			len_c = flags.precision;
		else if (flags.precision < 0)
			len_c = 0;
	}
	if (flags.minus)
	{
		count += write_string(c, flags);
		count += write_padding(flags.width, len_c, ' ');
	}
	else
	{
		count += write_padding(flags.width, len_c, ' ');
		count += write_string(c, flags);
	}
	return (count);
}

int	handle_string_flags(va_list args, t_flags flags)
{
	char	*c;
	int		count;

	count = 0;
	c = (char *)va_arg(args, char *);
	if (!c)
		c = "(null)";
	count += write_string_with_flags(c, flags);
	return (count);
}
