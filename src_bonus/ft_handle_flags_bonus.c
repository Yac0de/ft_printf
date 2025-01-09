/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_flags_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:30:18 by ymeziane          #+#    #+#             */
/*   Updated: 2023/10/31 18:40:42 by ymeziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_flags	init_flags(void)
{
	t_flags	flags;

	flags.minus = 0;
	flags.zero = 0;
	flags.dot = 0;
	flags.hash = 0;
	flags.plus = 0;
	flags.space = 0;
	flags.width = 0;
	flags.precision = -1;
	return (flags);
}

static const char	*handle_simple_flags(const char *format, t_flags *flags)
{
	while (*format == '-' || *format == '0' || *format == '#' || *format == '+'
		|| *format == ' ')
	{
		if (*format == '-')
			flags->minus = 1;
		else if (*format == '0')
			flags->zero = 1;
		else if (*format == '#')
			flags->hash = 1;
		else if (*format == '+')
			flags->plus = 1;
		else if (*format == ' ')
			flags->space = 1;
		format++;
	}
	return (format);
}

static const char	*handle_dot_flag(const char *format, t_flags *flags)
{
	flags->precision = 0;
	flags->dot = 1;
	format++;
	if (ft_isdigit(*format))
		flags->precision = ft_atoi(format);
	while (ft_isdigit(*format))
		format++;
	return (format);
}

static const char	*handle_width_flag(const char *format, t_flags *flags)
{
	flags->width = ft_atoi(format);
	while (ft_isdigit(*format))
		format++;
	return (format);
}

const char	*parse_flags(const char *format, t_flags *flags)
{
	while (1)
	{
		if (*format == '-' || *format == '0' || *format == '#' || *format == '+'
			|| *format == ' ')
			format = handle_simple_flags(format, flags);
		else if (*format == '.')
			format = handle_dot_flag(format, flags);
		else if (ft_isdigit(*format))
			format = handle_width_flag(format, flags);
		else
			break ;
	}
	return (format);
}
