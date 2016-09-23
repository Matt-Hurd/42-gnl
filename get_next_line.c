/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 21:30:44 by mhurd             #+#    #+#             */
/*   Updated: 2016/09/23 02:49:21 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

void	handle_extra(char *extra, char *ret, char **end)
{
	long	dist;

	dist = ft_strchr(extra, '\n') - extra;
	if (ft_strchr(extra, '\n'))
	{
		*end = (char *)1;
		extra[dist] = 0;
		ft_strcpy(ret, extra);
		ft_memmove(extra, extra + dist + 1, BUFF_SIZE - dist - 1);
	}
	else
	{
		ft_memcpy(ret, extra, BUFF_SIZE);
		ft_strclr(extra);
	}
}

char	*handle_data(int count, char **ret, char *buff, char extra[BUFF_SIZE])
{
	long	dist;
	int		len;

	len = ft_strlen(*ret);
	dist = (long)(ft_strchr(buff, '\n') - buff);
	if (!ft_strchr(buff, '\n'))
	{
		*ret = (char *)ft_realloc((void *)*ret, len, len + count + 1);
		ft_strncat(*ret, buff, count);
	}
	else
	{
		*ret = (char *)ft_realloc((void *)*ret, len, len + dist + 1);
		ft_strncat(*ret, buff, dist);
		ft_strncpy(extra, buff + dist + 1, BUFF_SIZE - dist - 1);
	}
	return (ft_strchr(buff, '\n'));
}

int		get_next_line(const int fd, char **line)
{
	static char extra[BUFF_SIZE + 1];
	char		*buffer;
	char		*ret;
	int			count;
	char		*end;

	buffer = ft_strnew(BUFF_SIZE);
	ret = ft_strnew(BUFF_SIZE);
	end = 0;
	handle_extra(extra, ret, &end);
	while (!end && (count = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		end = handle_data(count, &ret, buffer, extra);
	}
	if (end > buffer)
		ft_strcpy(extra, end + 1);
	*line = ret;
	if (end || ret[0] || buffer[0] || count)
	{
		ft_strdel(&buffer);
		return ((count >= 0 ? 1 : -1));
	}
	ft_strdel(&buffer);
	return (0);
}
