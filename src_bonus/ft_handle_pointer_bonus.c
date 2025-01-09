/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pointer_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:41:39 by ymeziane          #+#    #+#             */
/*   Updated: 2023/10/30 10:09:40 by ymeziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static size_t	get_hex_len(uintptr_t ptr)
{
	size_t	len;

	len = 0;
	if (ptr == 0)
		return (1);
	while (ptr)
	{
		ptr /= 16;
		len++;
	}
	return (len);
}

static int	write_padding(int width, int len, char padding_char)
{
	int	count;

	count = 0;
	while (width > len)
	{
		write(1, &padding_char, 1);
		count++;
		width--;
	}
	return (count);
}

static int	print_hex_recursive_ptr(uintptr_t ptr)
{
	const char	hex_chars[] = "0123456789abcdef";
	int			count;

	count = 0;
	if (ptr >= 16)
		count += print_hex_recursive_ptr(ptr / 16);
	write(1, &hex_chars[ptr % 16], 1);
	count++;
	return (count);
}

static int	write_pointer_with_flags(uintptr_t ptr, t_flags flags, size_t len)
{
	int	count;

	count = 0;
	if (flags.minus)
	{
		if (ptr)
			count += write(1, "0x", 2);
		if (ptr)
			count += print_hex_recursive_ptr(ptr);
		else
			count += write(1, "(nil)", ft_strlen("(nil)"));
		count += write_padding(flags.width, len, ' ');
	}
	else
	{
		count += write_padding(flags.width, len, ' ');
		if (ptr)
			count += write(1, "0x", 2);
		if (ptr)
			count += print_hex_recursive_ptr(ptr);
		else
			count += write(1, "(nil)", ft_strlen("(nil)"));
	}
	return (count);
}

int	handle_pointer_flags(va_list args, t_flags flags)
{
	uintptr_t	ptr;
	int			count;
	size_t		len;

	count = 0;
	len = 0;
	ptr = (uintptr_t)va_arg(args, void *);
	if (!ptr)
		len = ft_strlen("(nil)");
	else
		len = get_hex_len(ptr) + 2;
	count = write_pointer_with_flags(ptr, flags, len);
	return (count);
}
