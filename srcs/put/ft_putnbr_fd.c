/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyyyyy <yyyyyy@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:23:22 by bguyot            #+#    #+#             */
/*   Updated: 2024/11/21 05:52:09 by yyyyyy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_put.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb < 0)
	{
		write(1, "-", fd);
		if (nb <= -10)
			ft_putnbr_fd(nb / -10, fd);
		ft_putchar_fd((-1 * (nb % 10)) + '0', fd);
	}
	else if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd);
	if (nb >= 0)
		ft_putchar_fd(nb % 10 + '0', fd);
}
