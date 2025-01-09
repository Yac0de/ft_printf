/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_int_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 19:19:10 by ymeziane          #+#    #+#             */
/*   Updated: 2023/10/31 17:25:26 by ymeziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	handle_precision(int val, int precision)
{
	int				count;
	unsigned int	digits;

	count = 0;
	digits = ft_count_digit(val);
	if (precision <= (int)digits)
		return (count);
	while (precision > (int)digits)
	{
		write(1, "0", 1);
		count++;
		precision--;
	}
	return (count);
}

static int	write_padding(t_flags flags, int digits, char padding_char,
		long val)
{
	int	count;

	count = 0;
	if (flags.precision > digits - (val < 0 || flags.plus))
	{
		digits = flags.precision;
		if (val < 0 || flags.plus)
			digits++;
	}
	if (flags.precision == digits && flags.space && !flags.plus)
		digits++;
	if (flags.width < flags.precision)
		flags.width = flags.precision;
	while (flags.width > digits)
	{
		write(1, &padding_char, 1);
		count++;
		flags.width--;
	}
	return (count);
}

static int	handle_negative_val(long val, t_flags flags)
{
	int	count;

	count = 0;
	if (val == INT_MIN)
	{
		write(1, "-2147483648", 11);
		return (0);
	}
	write(1, "-", 1);
	count += handle_precision(-val, flags.precision);
	ft_putnbr_fd(-val, 1);
	return (count);
}

static int	write_number(long val, t_flags flags)
{
	int	count;

	count = 0;
	if (!flags.precision && !val)
		return (0);
	if (flags.plus && val >= 0 && (!flags.zero || flags.precision != -1))
		write(1, "+", 1);
	if (val < 0)
		count += handle_negative_val(val, flags);
	else
	{
		count += handle_precision(val, flags.precision);
		if (val == 2147483648)
			write(1, "2147483648", 10);
		else
			ft_putnbr_fd(val, 1);
	}
	return (count);
}

int	handle_int_flags(va_list args, t_flags flags)
{
	long	val;
	int		count;
	char	padding_char;

	val = (long)va_arg(args, int);
	padding_char = set_padding_char(flags);
	count = count_digits_flags(val, flags);
	count += handle_space_and_plus(flags, val);
	if (flags.minus)
	{
		count += write_number(val, flags);
		count += write_padding(flags, count, padding_char, val);
	}
	else
	{
		val = handle_negative_with_padding(val, padding_char);
		count += write_padding(flags, count, padding_char, val);
		count += write_number(val, flags);
	}
	return (count);
}
