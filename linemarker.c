/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linemarker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 13:01:44 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/09/24 21:49:48 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void		pixel_connect(t_data *data, t_pixel origin, t_pixel target)
{
	int dx;
	int dy;
	int delta[2];
	int failure[2];

	dx = ft_abs(target.x - origin.x);
	dy = ft_abs(target.y - origin.y);
	delta[0] = (origin.x < target.x ? 1 : -1);
	delta[1] = (origin.y < target.y ? 1 : -1);
	failure[0] = (dx > dy ? dx : -dy) / 2;
	while (origin.x != target.x || origin.y != target.y)
	{
		add_pixel(data, origin.x, origin.y, data->color);
		failure[1] = failure[0];
		if (failure[1] > -dx)
		{
			failure[0] -= dy;
			origin.x += delta[0];
		}
		if (failure[1] < dy)
		{
			failure[0] += dx;
			origin.y += delta[1];
		}
	}
}

void			vector_mark(t_data *data)
{
	int x;
	int y;

	x = 0;
	y = 0;
	do_mapping(data);
	mlx_clear_window(data->mlx, data->window);
	while (y < data->height)
	{
		while (x < data->width)
		{
			mark_hill(data, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}

void			mark_hill(t_data *data, int x, int y)
{
	t_pixel pixel[2];

	pixel[0].x = data->matrix[y][x].pos_x;
	pixel[0].y = data->matrix[y][x].pos_y;
	if (x < data->width - 1)
	{
		pixel[1].x = data->matrix[y][x + 1].pos_x;
		pixel[1].y = data->matrix[y][x + 1].pos_y;
		pixel_connect(data, pixel[0], pixel[1]);
	}
	if (y < data->height - 1)
	{
		pixel[1].x = data->matrix[y + 1][x].pos_x;
		pixel[1].y = data->matrix[y + 1][x].pos_y;
		pixel_connect(data, pixel[0], pixel[1]);
	}
}
