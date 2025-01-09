/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:57:45 by ymeziane          #+#    #+#             */
/*   Updated: 2023/10/26 17:57:45 by ymeziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/inc/libft.h"
# include <stdarg.h>
# include <stdint.h>

int	ft_printf(const char *format, ...);
int	process_string(const char *format, va_list args);
int	handle_char(va_list args);
int	handle_string(va_list args);
int	handle_pointer(va_list args);
int	handle_int(va_list args);
int	handle_unsigned(va_list args);
int	handle_hex(va_list args, char letter);
int	handle_percent(char percent);

#endif