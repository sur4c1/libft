/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expend_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyyyyy <yyyyyy@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:06:19 by bguyot            #+#    #+#             */
/*   Updated: 2024/11/21 06:12:39 by yyyyyy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_printf.h"

/*\*/
static t_parse	*g_parser[] = {
	['u'] = *(__u),
	['x'] = *(__x),
	['X'] = *(__great_x),
	['i'] = *(__i),
	['p'] = *(__p),
	['d'] = *(__d),
	['%'] = *(__percent),
	['s'] = *(__s),
	['c'] = *(__c),
	['f'] = *(__f)
};
/**/

t_buff	*__expend_arg(va_list args, t_flag *flag)
{
	t_buff	*ret;

	ret = g_parser[flag->conv_type](args, flag);
	__apply_width(ret, flag);
	return (ret);
}
