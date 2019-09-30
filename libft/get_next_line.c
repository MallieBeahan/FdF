/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 19:23:25 by mbeahan           #+#    #+#             */
/*   Updated: 2019/09/30 17:15:34 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_gnl(int fd, char **line, char **res, int ret)
{
	char *tmp;

	if (ret == 0 && (res[fd] == NULL || res[fd][0] == '\0'))
		return (0);
	if (ret == 0 && ft_strchr(res[fd], '\n') == NULL)
	{
		*(line) = ft_strsub(res[fd], 0, ft_strlen(res[fd]));
		ft_strdel(&res[fd]);
		return (1);
	}
	else if (ret == 0 && ft_strchr(res[fd], '\n') != NULL)
	{
		*line = ft_strsub(res[fd], 0, \
		ft_strchr(res[fd], '\n') - (res[fd]));
		tmp = ft_strsub(res[fd], (ft_strchr(res[fd], '\n') - (res[fd])) \
		+ 1, ft_strlen(res[fd]) - (ft_strchr(res[fd], '\n') - (res[fd])));
		free(res[fd]);
		res[fd] = tmp;
		return (1);
	}
	if (ret < 0)
		return (-1);
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	static char	*res[MAX_FD];
	char		*tmp;
	int			ret;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		res[fd] == NULL ? res[fd] = ft_strnew(BUFF_SIZE) : 0;
		tmp = ft_strjoin(res[fd], (char *)buff);
		free(res[fd]);
		res[fd] = tmp;
		if (ft_strchr(res[fd], '\n') != NULL)
		{
			*line = ft_strsub(res[fd], 0, ft_strchr(res[fd], '\n') - (res[fd]));
			tmp = ft_strsub(res[fd], (ft_strchr(res[fd], '\n') - (res[fd])) \
			+ 1, ft_strlen(res[fd]) - (ft_strchr(res[fd], '\n') - (res[fd])));
			free(res[fd]);
			res[fd] = tmp;
			return (1);
		}
	}
	return (ft_check_gnl(fd, line, res, ret));
}
