/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyyyyy <yyyyyy@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 08:50:10 by bguyot            #+#    #+#             */
/*   Updated: 2024/11/21 06:10:14 by yyyyyy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_printf.h"

t_buff	*__p(va_list lst, t_flag *flag)
{
	t_buff	*ret;
	void	*data;
	char	*tmp;

	ret = ft_calloc(1, sizeof (t_buff));
	data = va_arg(lst, void *);
	tmp = ft_ultoa_base((unsigned long) data, "0123456789abcdef");
	ret->data = ft_strjoin("0x", tmp);
	free (tmp);
	if (flag->precision == 0 && data == NULL)
	{
		tmp = ft_strdup("0x");
		free(ret->data);
		ret->data = tmp;
	}
	ret->len = ft_strlen(ret->data);
	return (ret);
	(void) flag;
}
