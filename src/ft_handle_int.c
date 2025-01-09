/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_int.c                                       :+:   :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 19:19:10 by ymeziane          #+#    #+#             */
/*   Updated: 2023/10/27 17:04:02 by ymeziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_int(va_list args)
{
	int	count;
	int	val;

	val = (int)va_arg(args, int);
	count = (int)ft_count_digit(val);
	if (val < 0)
		count++;
	ft_putnbr_fd(val, 1);
	return (count);
}
