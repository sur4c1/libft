/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyyyyy <yyyyyy@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 07:34:46 by bguyot            #+#    #+#             */
/*   Updated: 2024/11/25 14:02:06 by yyyyyy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ft_printf.h"
#include "ft_buff.h"
#include "ft_memory.h"
#include "ft_string.h"
#include <stdarg.h>

void	__ft_printf(char *format, va_list ap, t_buff *buff);
