/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 17:48:38 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/09/24 21:49:33 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int			add_mouse(int num_button, int x, int y, t_data *data)
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
		vector_mark(data);
	}
	return (MOUSE_LEFT_BUTTON);
}

int     add_keys(int num_button, t_data *data)
{
    if (num_button == MAIN_PAD_ESC)
        exit(0);
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
    if (num_button == NUM_PAD_MINUS)
    {
        data->scope.x -= 1;
        data->scope.y += 1;
    }
   /* if (num_button == MAIN_PAD_W)
	{
		data->altitude += 1;
		mapping_height(data, 1);
    }
    if (num_button == MAIN_PAD_S)
	{
		data->altitude -= 1;
		mapping_height(data, -1);
    }
    */
    vector_mark(data);
    return(1);
}

int close_window_on_x(int button, void *mlx)
{
    (void)button;   
    (void)mlx;
    exit(0);
    return (0);
}
