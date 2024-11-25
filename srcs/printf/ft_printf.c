/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyyyyy <yyyyyy@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:11:52 by yyyyyy            #+#    #+#             */
/*   Updated: 2024/11/25 14:09:41 by yyyyyy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "__ft_printf.h"

static struct s_buff_fd {
	t_buff		buff;
	int			fd;
}				*g_buff;
static size_t	g_fd_nb;

__attribute__((constructor))
void init_buff(void)
{
	g_fd_nb = 1;
	g_buff = ft_calloc(g_fd_nb, sizeof(struct s_buff_fd));
}

__attribute__((destructor))
void free_buff(void)
{
	size_t	i;

	i = 0;
	while (i < g_fd_nb)
	{
		write(g_buff[i].fd, g_buff[i].buff.data, g_buff[i].buff.len);
		free(g_buff[i].buff.data);
		i++;
	}
	free(g_buff);
}

static
t_buff	*find_buff(int fd)
{
	size_t				i;
	struct s_buff_fd	*tmp;

	i = 0;
	while (i < g_fd_nb)
	{
		if (g_buff[i].fd == fd)
			return (&g_buff[i].buff);
		i++;
	}
	g_fd_nb++;
	tmp = ft_calloc(g_fd_nb, sizeof(struct s_buff_fd));
	ft_memcpy(tmp, g_buff, (g_fd_nb - 1) * sizeof(struct s_buff_fd));
	g_buff[g_fd_nb - 1].fd = fd;
	return (&g_buff[g_fd_nb - 1].buff);
}

int ft_printf(const char *restrict format, ...)
{
	va_list	ap;
	t_buff	*buff;
	char	*tmp;
	size_t	len;

	buff = find_buff(1);
	va_start(ap, format);
	__ft_printf((char *)format, ap, buff);
	va_end(ap);
	len = buff->len;
	while (len--)
	{
		if (buff->data[len] == '\n')
			break ;
	}
	write(1, buff->data, len);
	buff->len -= len;
	tmp = ft_memdup(buff->data + len, buff->len);
	free(buff->data);
	buff->data = tmp;
	return (buff->len);
}
