/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyyyyy <yyyyyy@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:47:50 by bguyot            #+#    #+#             */
/*   Updated: 2024/11/21 06:13:05 by yyyyyy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_printf.h"

int	ft_printf(const char *ft_format, ...)
{
	t_list	*module;
	t_buff	*out;
	int		ret;
	va_list	args;

	if (!ft_strlen(ft_format))
		return (0);
	va_start(args, ft_format);
	module = __ft_split_module(ft_format);
	__ft_parse(module, args);
	out = __ft_stringify(module);
	ft_lstclear(&module, *ft_bufclear);
	write(1, out->data, out->len);
	ret = out->len;
	ft_bufclear(out);
	va_end(args);
	return (ret);
}
