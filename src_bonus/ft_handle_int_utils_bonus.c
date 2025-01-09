/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_int_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:24:00 by ymeziane          #+#    #+#             */
/*   Updated: 2023/10/31 17:25:51 by ymeziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	count_digits_flags(int val, t_flags flags)
{
	int	count;

	count = 0;
	if (!flags.precision && val == 0)
		return (0);
	if (val < 0 || flags.plus)
		count += ft_count_digit(val) + 1;
	else
		count += ft_count_digit(val);
	return (count);
}

int	set_padding_char(t_flags flags)
{
	if (flags.zero && !flags.minus && !flags.dot)
		return ('0');
	return (' ');
}

long	handle_negative_with_padding(long val, char padding_char)
{
	if (padding_char == '0' && val < 0)
	{
		write(1, "-", 1);
		val = -val;
	}
	return (val);
}

int	handle_space_and_plus(t_flags flags, long val)
{
	int	count;

	count = 0;
	if (flags.space && val >= 0 && !flags.plus)
		count += write(1, " ", 1);
	if (flags.plus && val >= 0 && flags.zero && flags.precision == -1)
		write(1, "+", 1);
	return (count);
}
