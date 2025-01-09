/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex_utils_bonus.c                         :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:21:51 by ymeziane          #+#    #+#             */
/*   Updated: 2023/10/31 15:42:12 by ymeziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	determine_padding_char(t_flags flags)
{
	if (flags.zero && !flags.dot && flags.precision == -1)
		return ('0');
	return (' ');
}

int	handle_hex_no_minus(t_flags flags, unsigned int val, const char letter,
int digits)
{
	int		count;
	char	padding_char;

	count = 0;
	padding_char = determine_padding_char(flags);
	if (padding_char == '0')
		count += handle_hash_flag(flags, letter, val);
	count += write_padding_hex(flags, digits, padding_char, val);
	if (padding_char == ' ' && flags.hash && val > 0)
		count += handle_hash_flag(flags, letter, val);
	return (count);
}

int	print_hex_with_len(unsigned int val, const char letter)
{
	print_hex_recursive(val, letter);
	return (ft_hex_len(val));
}
