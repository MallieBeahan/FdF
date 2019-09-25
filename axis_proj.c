/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axis_proj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 19:21:14 by mbeahan           #+#    #+#             */
/*   Updated: 2019/09/25 16:25:17 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static int			mapping_ox(t_data *data, int x, int y)
{
	double bit;

	bit = (M_SQRT2 / 2) * (x - y);
	bit *= data->scope.x;
	return ((int)bit);
}

static int			mapping_oy(t_data *data, int x, int y)
{
	double bit;

	bit = (sqrt(3 / 2) * data->matrix[y][x].z);
	bit -= (1 / sqrt(6) * (x + y));
	bit *= data->scope.y;
	return ((int)bit);
}

void				mapping_height(t_data *data, int flag)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < data->height)
	{
		while (x < data->width)
		{
			if (data->matrix[y][x].z0 != 0)
			{
				if (flag == 1)
					data->matrix[y][x].z = (data->matrix[y][x].z0 *
					data->altitude);
				else
					data->matrix[y][x].z = (data->matrix[y][x].z0 *
					data->altitude);
				data->matrix[y][x].pos_x = mapping_ox(data, x, y);
				data->matrix[y][x].pos_y = mapping_oy(data, x, y);
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void				do_mapping(t_data *data)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < data->height)
	{
		while (x < data->width)
		{
			data->matrix[y][x].pos_x = mapping_ox(data, x, y);
			data->matrix[y][x].pos_y = mapping_oy(data, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}
