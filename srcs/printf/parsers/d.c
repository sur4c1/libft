/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyyyyy <yyyyyy@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 08:48:18 by bguyot            #+#    #+#             */
/*   Updated: 2024/11/21 06:10:57 by yyyyyy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_printf.h"

t_buff	*__d(va_list lst, t_flag *flag)
{
	t_buff	*ret;
	int		data;
	char	*tmp;

	ret = ft_calloc(1, sizeof (t_buff));
	data = va_arg(lst, int);
	ret->data = ft_itoa(data);
	if (data < 0)
	{
		tmp = ft_substr(ret->data, 1, ft_strlen(ret->data) - 1);
		free(ret->data);
		ret->data = tmp;
	}
	__update_flag(flag, data, ret);
	if (data == 0 && flag->precision == 0)
	{
		tmp = ft_strdup("");
		free(ret->data);
		ret->data = tmp;
	}
	ret->len = ft_strlen(ret->data);
	return (ret);
}
