/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_unsigned_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 19:36:15 by ymeziane          #+#    #+#             */
/*   Updated: 2023/10/31 10:24:30 by ymeziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static unsigned int	count_digit_unsigned(unsigned int n)
{
	unsigned int	digits;

	digits = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		digits++;
		n /= 10;
	}
	return (digits);
}

static int	handle_precision(unsigned int val, int precision)
{
	int				count;
	unsigned int	digits;

	count = 0;
	digits = count_digit_unsigned(val);
	while (precision > (int)digits)
	{
		write(1, "0", 1);
		precision--;
		count++;
	}
	return (count);
}

static int	write_padding(t_flags flags, int digits, char padding_char,
unsigned int val)
{
	int	count;

	count = 0;
	if (flags.precision > digits)
		digits = flags.precision;
	else if (flags.precision == 0 && val == 0)
		digits = 0;
	while (flags.width > digits)
	{
		write(1, &padding_char, 1);
		count++;
		flags.width--;
	}
	return (count);
}

static int	ft_putnbr_unsignedint_fd(unsigned int n, unsigned int fd,
		int precision)
{
	int	count;

	count = 0;
	if (!precision && !n)
		return (count);
	if (n >= 10)
		count += ft_putnbr_unsignedint_fd(n / 10, fd, precision - 1);
	else
		count += handle_precision(n, precision);
	ft_putchar_fd((n % 10) + '0', fd);
	count++;
	return (count);
}

int	handle_unsigned_flags(va_list args, t_flags flags)
{
	int				count;
	unsigned int	val;
	char			padding_char;

	val = (unsigned int)va_arg(args, unsigned int);
	if (flags.zero && !flags.minus && !flags.dot)
		padding_char = '0';
	else
		padding_char = ' ';
	count = 0;
	if (flags.minus)
	{
		count += ft_putnbr_unsignedint_fd(val, 1, flags.precision);
		count += write_padding(flags, count_digit_unsigned(val),
				padding_char, val);
	}
	else
	{
		count += write_padding(flags, count_digit_unsigned(val),
				padding_char, val);
		count += ft_putnbr_unsignedint_fd(val, 1, flags.precision);
	}
	return (count);
}
