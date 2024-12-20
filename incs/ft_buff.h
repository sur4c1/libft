/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyyyyy <yyyyyy@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 07:42:27 by bguyot            #+#    #+#             */
/*   Updated: 2024/11/25 13:39:50 by yyyyyy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUFF_H
# define FT_BUFF_H

# include <stddef.h>
# include <stdlib.h>
# include "ft_memory.h"

# ifndef T_BUFF
#  define T_BUFF

typedef struct s_buff
{
	char	*data;
	size_t	len;
}	t_buff;

# endif

/* concatenante two buffers (new data is allocated) */
t_buff	ft_bufcat(t_buff a, t_buff b);

/* free data and set len to 0 */
void	ft_bufclear(t_buff buf);

/* create new buff with a copy of data */
t_buff	ft_bufdup(t_buff src);

#endif
