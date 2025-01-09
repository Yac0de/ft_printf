/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:47:32 by ymeziane          #+#    #+#             */
/*   Updated: 2023/10/31 09:51:37 by ymeziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	handle_precision(int val, int precision)
{
	int				count;
	unsigned int	digits;

	count = 0;
	if (val == 0 && precision == 0)
		return (count);
	digits = ft_hex_len(val);
	while (precision > (int)digits)
	{
		write(1, "0", 1);
		count++;
		precision--;
	}
	return (count);
}

int	handle_hash_flag(t_flags flags, char letter, unsigned int val)
{
	int	count;

	count = 0;
	if (flags.hash && val != 0)
	{
		if (letter == 'x')
		{
			write(1, "0x", 2);
			count = 2;
		}
		else
		{
			write(1, "0X", 2);
			count = 2;
		}
	}
	return (count);
}

int	write_padding_hex(t_flags flags, int digits, char padding_char,
unsigned int val)
{
	int	count;

	count = 0;
	if (flags.precision > digits)
		digits = flags.precision;
	else if (flags.precision == 0 && val == 0)
		digits = 0;
	if (flags.hash && val > 0)
		digits += 2;
	while (flags.width > digits)
	{
		write(1, &padding_char, 1);
		count++;
		flags.width--;
	}
	return (count);
}

void	print_hex_recursive(unsigned int val, char letter)
{
	const char	lowercase_hex_chars[] = "0123456789abcdef";
	const char	uppercase_hex_chars[] = "0123456789ABCDEF";

	if (val >= 16)
		print_hex_recursive(val / 16, letter);
	if (letter == 'x')
		write(1, &lowercase_hex_chars[val % 16], 1);
	else
		write(1, &uppercase_hex_chars[val % 16], 1);
}

int	handle_hex_flags(va_list args, t_flags flags, const char letter)
{
	unsigned int	val;
	int				count;
	int				digits;

	val = va_arg(args, unsigned int);
	digits = ft_hex_len(val);
	count = 0;
	if (!flags.minus)
		count += handle_hex_no_minus(flags, val, letter, digits);
	else
		count += handle_hash_flag(flags, letter, val);
	if (flags.dot)
		count += handle_precision(val, flags.precision);
	if (!(flags.precision == 0 && val == 0))
		count += print_hex_with_len(val, letter);
	if (flags.minus)
		count += write_padding_hex(flags, digits, ' ', val);
	return (count);
}
