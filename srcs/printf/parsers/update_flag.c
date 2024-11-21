/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyyyyy <yyyyyy@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 09:27:34 by bguyot            #+#    #+#             */
/*   Updated: 2024/11/21 12:57:53 by yyyyyy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_printf.h"

void	__update_flag(t_flag *flag, int data, t_buff *ret)
{
	flag->sign = ft_sign(data);
	if (!data)
		flag->sign = 1;
	if (data >= 0 && !flag->positive_sign)
		flag->sign = 0;
	__update_zero_flag(flag, ret);
}

void	__update_zero_flag(t_flag *flag, t_buff *ret)
{
	if (flag->precision >= 0)
	{
		if (flag->padding_type == '0')
			flag->padding_type = 0;
		flag->zero_prec = flag->precision - ft_strlen(ret->data);
		if (flag->zero_prec < 0)
			flag->zero_prec = 0;
	}
}
