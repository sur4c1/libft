/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringify.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyyyyy <yyyyyy@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 07:42:03 by bguyot            #+#    #+#             */
/*   Updated: 2024/11/21 06:13:05 by yyyyyy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_printf.h"

/*
 *	ft_stringify
 *
 *	puts back all the tokens in a string
 *
 *	token:
 *		token list to transform in string
 */
t_buff	*__ft_stringify(t_list *token)
{
	t_buff	*ret;
	t_buff	*tmp;

	ret = NULL;
	while (token)
	{
		tmp = ret;
		ret = ft_bufcat(tmp, ((t_buff *) token->content));
		ft_bufclear(tmp);
		token = token->next;
	}
	return (ret);
}
