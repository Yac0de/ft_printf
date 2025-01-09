/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:16:46 by ymeziane          #+#    #+#             */
/*   Updated: 2023/10/31 17:50:02 by ymeziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "../libft/inc/libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>

typedef struct s_flags
{
	int	minus;
	int	zero;
	int	dot;
	int	hash;
	int	plus;
	int	space;
	int	width;
	int	precision;
}	t_flags;

int			ft_printf(const char *format, ...);
int			process_string_bonus(const char *format, va_list args);

int			handle_char_flags(va_list args, t_flags flags);
int			handle_string_flags(va_list args, t_flags flags);
int			handle_pointer_flags(va_list args, t_flags flags);
int			handle_int_flags(va_list args, t_flags flags);
int			handle_hex_flags(va_list args, t_flags flags, const char letter);
int			handle_space_and_plus(t_flags flags, long val);
int			handle_unsigned_flags(va_list args, t_flags flags);
int			handle_percent_bonus(char percent);

int			count_digits_flags(int val, t_flags flags);
int			set_padding_char(t_flags flags);
long		handle_negative_with_padding(long val, char padding_char);
int			handle_space_and_plus(t_flags flags, long val);

int			handle_hash_flag(t_flags flags, char letter, unsigned int val);
int			write_padding_hex(t_flags flags, int digits, char padding_char,
				unsigned int val);
void		print_hex_recursive(unsigned int val, char letter);
char		determine_padding_char(t_flags flags);
int			handle_hex_no_minus(t_flags flags, unsigned int val,
				const char letter, int digits);
int			print_hex_with_len(unsigned int val, const char letter);

t_flags		init_flags(void);
const char	*parse_flags(const char *format, t_flags *flags);

#endif