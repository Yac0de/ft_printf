/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_string_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:56:13 by ymeziane          #+#    #+#             */
/*   Updated: 2023/10/31 18:56:13 by ymeziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	handle_specifier(const char specifier, va_list args, t_flags flags)
{
	if (specifier == 'c')
		return (handle_char_flags(args, flags));
	else if (specifier == 's')
		return (handle_string_flags(args, flags));
	else if (specifier == 'p')
		return (handle_pointer_flags(args, flags));
	else if (specifier == 'd' || specifier == 'i')
		return (handle_int_flags(args, flags));
	else if (specifier == 'u')
		return (handle_unsigned_flags(args, flags));
	else if (specifier == 'x' || specifier == 'X')
		return (handle_hex_flags(args, flags, specifier));
	else if (specifier == '%')
		return (handle_percent_bonus('%'));
	return (0);
}

int	process_string_bonus(const char *format, va_list args)
{
	int		count;
	t_flags	flags;

	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			flags = init_flags();
			format = parse_flags(format, &flags);
			count += handle_specifier(*format, args, flags);
			format++;
		}
		else
		{
			ft_putchar_fd(*format, 1);
			count++;
			format++;
		}
	}
	return (count);
}
