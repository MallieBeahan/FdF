/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 21:32:40 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/09/30 18:20:04 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#define STR "Raise or down the points 'R/F'."

void	print_menu(t_data *data)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = data->mlx;
	win = data->window;
	mlx_string_put(mlx, win, 15, y += 20, TEXT_COLOR, "How to Use");
	mlx_string_put(mlx, win, 15, y += 35, TEXT_COLOR, "Zoom: '+/-'");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, STR);
	mlx_string_put(mlx, win, 15, y += 25, TEXT_COLOR, "Move: Use arrows.");
	mlx_string_put(mlx, win, 15, y += 25, TEXT_COLOR, "Change colors 'C'");
}
