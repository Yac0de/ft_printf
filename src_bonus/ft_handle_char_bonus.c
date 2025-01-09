/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_char_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:55:44 by ymeziane          #+#    #+#             */
/*   Updated: 2023/10/31 18:55:44 by ymeziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	write_padding(int width)
{
	int	count;

	count = 0;
	while (width > 1)
	{
		write(1, " ", 1);
		count++;
		width--;
	}
	return (count);
}

static int	write_char_with_flags(char c, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.minus)
	{
		ft_putchar_fd(c, 1);
		count++;
		count += write_padding(flags.width);
	}
	else
	{
		count += write_padding(flags.width);
		ft_putchar_fd(c, 1);
		count++;
	}
	return (count);
}

int	handle_char_flags(va_list args, t_flags flags)
{
	int		count;
	char	c;

	c = (char)va_arg(args, int);
	count = 0;
	count += write_char_with_flags(c, flags);
	return (count);
}
