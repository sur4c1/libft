/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyyyyy <yyyyyy@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 07:58:18 by bguyot            #+#    #+#             */
/*   Updated: 2024/11/25 13:37:52 by yyyyyy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buff.h"

void	ft_bufclear(t_buff buf)
{
	free(buf.data);
	buf.data = NULL;
	buf.len = 0;
}
