/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __ft_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyyyyy <yyyyyy@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:11:54 by yyyyyy            #+#    #+#             */
/*   Updated: 2024/11/26 06:33:44 by yyyyyy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "__ft_printf.h"

static
size_t	parse_arg(char *format, va_list ap, t_buff *buff)
{
	size_t	len;
	str		string;

	len = 1;
	if (ft_strcmp(format, "%s") == 0)
	{
		string = va_arg(ap, str);
		*buff = ft_bufcat(*buff, (t_buff) {string, ft_strlen(string)});
		return (2);
	}
	return (len);
	(void) ap;
	(void) buff;
	(void) format;
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
