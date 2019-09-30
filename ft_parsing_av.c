/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_av.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 20:40:19 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/09/30 18:04:05 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static int			invalid(int reason)
{
	if (reason == 1)
	{
		ft_putstr_fd("Invalid map.\n", 2);
		exit(0);
	}
	return (0);
}

static int			geting_matrix(char *av, int flag)
{
	int		fd;
	int		ret;
	char	*ln;

	ret = 0;
	fd = open(av, O_RDONLY);
	if (flag == 1)
	{
		while (get_next_line(fd, &ln) > 0)
			ret++;
		close(fd);
	}
	else
	{
		get_next_line(fd, &ln);
		ret = char_counter(ln);
		while (get_next_line(fd, &ln) > 0)
		{
			if (char_counter(ln) != ret)
				invalid(1);
		}
		close(fd);
	}
	return (ret);
}

int					char_counter(const char *ln)
{
	char	charend;
	int		count;
	int		i;
	int		len;

	i = 0;
	count = 0;
	len = ft_strlen(ln);
	if (len > 0)
		charend = ln[0];
	while (i <= len)
	{
		if ((ln[i] == ' ' || ln[i] == '\0') && charend != ' ')
			count++;
		charend = ln[i];
		i++;
	}
	return (count);
}

void				parsing_av(char *av, t_data *data)
{
	int i;

	i = 0;
	data->height = geting_matrix(av, 1);
	data->width = geting_matrix(av, 2);
	data->matrix = (t_matrix **)malloc(sizeof(t_matrix *) * data->height);
	while (i < data->height)
	{
		data->matrix[i] = (t_matrix *)malloc(sizeof(t_matrix) * data->width);
		i++;
	}
}
