/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __ft_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyyyyy <yyyyyy@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:11:54 by yyyyyy            #+#    #+#             */
/*   Updated: 2024/11/26 06:04:54 by yyyyyy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "__ft_printf.h"

static
size_t	parse_argindex(char *format, int *arg_index, int current_index)
{
	size_t	len;

	len = 0;
	while (ft_isdigit(format[len]))
	{
		*arg_index = *arg_index * 10 + format[len] - '0';
		len++;
	}
}

static
size_t	parse_arg(char *format, va_list ap, t_buff *buff)
{
	t_conversion	conv;
	size_t			len;

	len = 1;
	conv = (t_conversion){0};
	len += parse_argindex(format + len, &conv.arg_index, 0);
	return (len);
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
