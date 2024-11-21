/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyyyyy <yyyyyy@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 07:41:11 by bguyot            #+#    #+#             */
/*   Updated: 2024/11/21 12:53:37 by yyyyyy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_printf.h"

static
t_flag	get_flag(char *token);
static
void	parse_flag(t_flag *flag, char c);
/*
 *	ft_parse
 *
 *	expends the tokens that must parsed
 *
 *	module:
 *		list of all the tokens
 *	args:
 *		argument list
 */
void	__ft_parse(t_list *module, va_list args)
{
	t_flag	flag;

	while (module)
	{
		flag = get_flag(((t_buff *) module->content)->data);
		if (flag.conv_type)
		{
			ft_bufclear(module->content);
			module->content = __expend_arg(args, &flag);
		}
		module = module->next;
	}
}

/*
 *	get_flag
 *
 *	creates the flags structure of each token
 *
 *	token:
 *		token to get flags from
 */
static
t_flag	get_flag(char *token)
{
	t_flag	ret;
	char	conv;

	conv = token[ft_strlen(token) - 1];
	ft_bzero(&ret, sizeof(t_flag));
	ret.precision = -1;
	if (token[0] != '%' || !__is_conversion(conv))
	{
		ret.conv_type = 0;
		return (ret);
	}
	ret.conv_type = conv;
	while (__is_flag(*(++token)))
		parse_flag(&ret, *token);
	ret.min_width = ft_atoi(token);
	token = ft_strnstr(token, ".", ft_strlen(token));
	if (token++)
		ret.precision = ft_atoi(token);
	return (ret);
}

/*
 *	parse_flag
 *
 *	edit the flags according to the character encontered
 *
 *	flag:
 *		pointer to the flag structure
 *	c:
 *		character to calculate for
 */
static
void	parse_flag(t_flag *flag, char c)
{
	if (c == '#')
		flag->do_alt_form = 1;
	else if (c == '+')
		flag->positive_sign = '+';
	else if (c == ' ' && !(flag->positive_sign == '+'))
		flag->positive_sign = ' ';
	else if (c == '0' && !(flag->padding_type == '-'))
		flag->padding_type = '0';
	else if (c == '-')
		flag->padding_type = '-';
}
