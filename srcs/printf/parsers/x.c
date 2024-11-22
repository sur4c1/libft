/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyyyyy <yyyyyy@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 08:50:37 by bguyot            #+#    #+#             */
/*   Updated: 2024/11/21 12:58:21 by yyyyyy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_printf.h"

t_buff	*__x(va_list lst, t_flag *flag)
{
	t_buff			*ret;
	char			*tmp;
	unsigned int	data;

	ret = ft_calloc(1, sizeof (t_buff));
	data = va_arg(lst, unsigned);
	ret->data = ft_utoa_base(data, "0123456789abcdef");
	if (data && flag->do_alt_form)
	{
		tmp = ft_strjoin("0x", ret->data);
		free(ret->data);
		ret->data = tmp;
	}
	__update_zero_flag(flag, ret);
	if (data == 0 && flag->precision == 0)
	{
		tmp = ft_strdup("");
		free(ret->data);
		ret->data = tmp;
	}
	ret->len = ft_strlen(ret->data);
	return (ret);
}
