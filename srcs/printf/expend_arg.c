/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expend_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyyyyy <yyyyyy@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:06:19 by bguyot            #+#    #+#             */
/*   Updated: 2024/11/21 05:52:09 by yyyyyy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_printf.h"

/*\*/
static t_parse	*g_parser[] = {
	['u'] = *(u),
	['x'] = *(x),
	['X'] = *(great_x),
	['i'] = *(i),
	['p'] = *(p),
	['d'] = *(d),
	['%'] = *(percent),
	['s'] = *(s),
	['c'] = *(c),
	['f'] = *(f)
};
/**/

t_buff	*expend_arg(va_list args, t_flag *flag)
{
	t_buff	*ret;

	ret = g_parser[flag->conv_type](args, flag);
	apply_width(ret, flag);
	return (ret);
}
