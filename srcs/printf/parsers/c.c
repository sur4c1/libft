/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyyyyy <yyyyyy@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 08:02:03 by bguyot            #+#    #+#             */
/*   Updated: 2024/11/21 06:08:44 by yyyyyy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_printf.h"

t_buff	*__c(va_list lst, t_flag *flag)
{
	t_buff	*ret;
	char	data;

	ret = ft_calloc(1, sizeof (t_buff));
	data = va_arg(lst, int);
	ret->len = 1;
	ret->data = ft_strndup(&data, 1);
	return (ret);
	(void) flag;
}
