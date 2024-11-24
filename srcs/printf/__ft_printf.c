/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __ft_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyyyyy <yyyyyy@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:11:54 by yyyyyy            #+#    #+#             */
/*   Updated: 2024/11/25 14:01:41 by yyyyyy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "__ft_printf.h"

static
int	parse_arg(char *format, va_list ap, t_buff *buff)
{
	return (1);
	(void) format;
	(void) ap;
	(void) buff;
}

static
int	parse_str(char *format, t_buff *buff)
{
	size_t	len;

	len = 0;
	while (format[len] && format[len] != '%')
		len++;
	*buff = ft_bufcat(*buff, (t_buff) {format, len});
	return (len);
}

void	__ft_printf(char *format, va_list ap, t_buff *buff)
{
	while (*format)
	{
		if (*format == '%')
			format += parse_arg(format, ap, buff);
		else
			format += parse_str(format, buff);
	}
	(void) ap;
}
