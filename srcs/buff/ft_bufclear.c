/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyyyyy <yyyyyy@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 07:58:18 by bguyot            #+#    #+#             */
/*   Updated: 2024/11/21 05:52:09 by yyyyyy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buff.h"

void	ft_bufclear(void *buf)
{
	if (!buf)
		return ;
	if (((t_buff *) buf)->data)
		free(((t_buff *) buf)->data);
	((t_buff *) buf)->data = NULL;
	((t_buff *) buf)->len = 0;
	free(buf);
}
