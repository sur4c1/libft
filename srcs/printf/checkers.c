/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyyyyy <yyyyyy@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 09:33:28 by bguyot            #+#    #+#             */
/*   Updated: 2024/11/21 06:11:50 by yyyyyy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_printf.h"

/*
 *	is_conversion
 *
 *	check if a char is a conversion token or not
 *
 *	to_check:
 *		the char to check
 */
int	__is_conversion(char to_check)
{
	return ((ft_strchr(FT_CONVERSIONS, to_check) != NULL));
}

/*
 *	is_flag
 *
 *	check if a char is a conversion flag or not
 *
 *	to_check:
 *		the char to check
 */
int	__is_flag(char to_check)
{
	return (ft_strchr(FT_FLAGS, to_check) != NULL);
}
