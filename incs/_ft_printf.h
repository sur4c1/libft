/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_printf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyyyyy <yyyyyy@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 07:34:46 by bguyot            #+#    #+#             */
/*   Updated: 2024/11/21 06:13:05 by yyyyyy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H

# include "ft_printf.h"

# ifndef T_FLAG
#  define T_FLAG

typedef struct s_flag
{
	int	conv_type;
	int	padding_type;
	int	positive_sign;
	int	do_alt_form;
	int	min_width;
	int	precision;
	int	sign;
	int	zero_prec;
}	t_flag;

# endif

# ifndef T_PARSE
#  define T_PARSE

typedef	t_buff	*(t_parse)(va_list, t_flag*);

# endif

# ifndef FT_CONVERSIONS
#  define FT_CONVERSIONS "uxXipd%scf"
# endif

# ifndef FT_FLAGS
#  define FT_FLAGS " 0-+#"
# endif

/*
 *	FT_PARSE
 */
void	__ft_parse(t_list *module, va_list args);
t_flag	__get_flag(char *token);
void	parse_flag(t_flag *flag_struct, char flag_char);

/*
 *	EXPEND_ARG
 */
t_buff	*__expend_arg(va_list args, t_flag *flag);
t_buff	*__u(va_list args, t_flag *flag);
t_buff	*__x(va_list args, t_flag *flag);
t_buff	*__i(va_list args, t_flag *flag);
t_buff	*__p(va_list args, t_flag *flag);
t_buff	*__d(va_list args, t_flag *flag);
t_buff	*__s(va_list args, t_flag *flag);
t_buff	*__c(va_list args, t_flag *flag);
t_buff	*__f(va_list args, t_flag *flag);
t_buff	*__percent(va_list args, t_flag *flag);
t_buff	*__great_x(va_list args, t_flag *flag);
void	__apply_width(t_buff *str, t_flag *flag);
void	create_padding(t_buff segment[5], t_flag *flag, int padding_space);
void	create_sign(t_buff segment[5], t_flag *flag);
t_buff	concat_segment(t_buff segment[5]);
void	__update_flag(t_flag *flag, int data, t_buff *ret);
void	update_zero_flag(t_flag *flag, t_buff *ret);

/*
 *	FT_SPLIT_MODULE
 */
t_list	*__ft_split_module(const char *ft_format);
void	add_buffer_to_list(
			t_list **lst,
			const char *beg_str,
			const char *end_str
			);

/*
 *	FT_STRINGIFY
 */
t_buff	*__ft_stringify(t_list *token);

/*
 *	CHECKERS
 */
int		__is_conversion(char to_check);
int		__is_flag(char to_check);

/*
 *	FREE_BUFF
 */
void	free_buff(void *buff);

#endif
