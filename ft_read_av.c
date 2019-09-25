/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_av.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:50:17 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/09/25 16:12:39 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void			find_min_matrix(t_data *data, int x, int y, int flag)
{
	size_t	module;

	if (flag == 0)
	{
		module = ft_abs(data->matrix[y][x].z);
		if ((!data->min_matrix && module != 0) || \
		(data->min_matrix > module && module != 0))
			data->min_matrix = module;
	}
	else
	{
		if (!data->min_matrix)
			data->min_matrix = 1;
		while (y < data->height)
		{
			while (x < data->width)
			{
				data->matrix[y][x].z /= data->min_matrix;
				data->matrix[y][x].z0 /= data->min_matrix;
				x++;
			}
			x = 0;
			y++;
		}
	}
}

void				read_av(char *av, t_data *data)
{
	int			fd;
	int			x;
	int			y;
	char		*ln;
	char		**split;

	x = 0;
	y = 0;
	fd = open(av, O_RDONLY);
	while (get_next_line(fd, &ln) > 0)
	{
		split = ft_strsplit(ln, ' ');
		while (*split != NULL)
		{
			data->matrix[y][x].z = ft_atoi(*split);
			find_min_matrix(data, x, y, 0);
			data->matrix[y][x].z0 = data->matrix[y][x].z;
			x++;
			split++;
		}
		x = 0;
		y++;
	}
	close(fd);
	find_min_matrix(data, 0, 0, 1);
}
