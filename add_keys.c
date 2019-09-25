/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 17:48:38 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/09/25 17:53:34 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int					add_mouse(int num_button, int x, int y, t_data *data)
{
	if (num_button == MOUSE_LEFT_BUTTON && x && y)
	{
		if (data->color == WHITE)
			data->color = GREEN;
		else if (data->color == GREEN)
			data->color = BLUE;
		else if (data->color == BLUE)
			data->color = PURPLE;
		else if (data->color == PURPLE)
			data->color = ORANGE;
		else if (data->color == ORANGE)
			data->color = RED;
		else
			data->color = WHITE;
	}
	return (MOUSE_LEFT_BUTTON);
}

static int			and_more(int num_button, t_data *data)
{
	if (num_button == MAIN_PAD_R)
	{
		data->altitude += 1;
		mapping_height(data, 1);
	}
	if (num_button == NUM_PAD_MINUS)
	{
		data->scope.x -= 1;
		data->scope.y += 1;
	}
	return (num_button);
}

static int			add_morekeys(int num_button, t_data *data)
{
	if (num_button == MAIN_PAD_C)
	{
		if (data->color == WHITE)
			data->color = GREEN;
		else if (data->color == GREEN)
			data->color = BLUE;
		else if (data->color == BLUE)
			data->color = PURPLE;
		else if (data->color == PURPLE)
			data->color = ORANGE;
		else if (data->color == ORANGE)
			data->color = RED;
		else
			data->color = WHITE;
	}
	return (1);
}

int					add_keys(int num_button, t_data *data)
{
	if (num_button == MAIN_PAD_ESC)
		fdf_free(data);
	if (num_button == ARROW_RIGHT || num_button == MAIN_PAD_D)
		data->position.x += 30;
	if (num_button == ARROW_LEFT || num_button == MAIN_PAD_A)
		data->position.x -= 30;
	if (num_button == ARROW_DOWN || num_button == MAIN_PAD_S)
		data->position.y += 30;
	if (num_button == ARROW_UP || num_button == MAIN_PAD_W)
		data->position.y -= 30;
	if (num_button == NUM_PAD_PLUS)
	{
		data->scope.x += 1;
		data->scope.y -= 1;
	}
	if (num_button == MAIN_PAD_F)
	{
		data->altitude -= 1;
		mapping_height(data, -1);
	}
	add_morekeys(num_button, data);
	and_more(num_button, data);
	vector_mark(data);
	return (1);
}

void				fdf_free(t_data *data) 
{
	int i;
	
	i = 0;
	while(i < data->height)
	{
		free(data->matrix[i]);
		i++;	
	}
	if (data->matrix)
		free(data->matrix);
	free(data);
	mlx_destroy_window(data->mlx, data->window);
	exit(0);
}
