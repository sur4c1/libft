/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyyyyy <yyyyyy@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:21:40 by bguyot            #+#    #+#             */
/*   Updated: 2024/11/21 06:09:03 by yyyyyy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_printf.h"

t_buff	*__f(va_list lst, t_flag *flag)
{
	double	data;
	t_buff	*ret;

	ret = ft_calloc(1, sizeof (t_buff));
	ret->data = ft_strdup("(not implemented)");
	ret->len = ft_strlen(ret->data);
	data = va_arg(lst, double);
	return (ret);
	(void) flag;
	(void) data;
}
