/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 15:19:02 by mbeahan           #+#    #+#             */
/*   Updated: 2019/09/25 21:14:31 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void		initialize(t_data *data)
{
	if ((data->mlx = mlx_init()) == (void *)0)
	{
		ft_putstr_fd("MLX Error.", 2);
		fdf_free(data);
	}
	data->scope.x = 40;
	data->scope.y = -40;
	data->position.x = 500;
	data->position.y = 500;
	data->altitude = 1;
	data->color = WHITE;
}

static void		reprint_scope(t_data *data)
{
	while (data->scope.x * data->width > WIN_H && data->scope.x > 0)
		data->scope.x -= 1;
	while (data->scope.y * data->height < -WIN_W && data->scope.y < 0)
		data->scope.y += 1;
	if (ft_abs(data->scope.x) < ft_abs(data->scope.y))
		data->scope.y = -(data->scope.x);
	else
		data->scope.x = -(data->scope.y);
}

static int		error_checker(int ac)
{
	if (ac != 2)
	{
		ft_putstr_fd("Wrong argument's number.\n", 2);
		exit(0);
	}
	return (1);
}

void			check_args(int ac, t_data *data)
{
	if (ac != 2)
	{
		ft_putstr_fd("Error: Тot enough arguments.\n", 2);
		ft_putstr_fd("Usage: ./fdf file.fdf\n", 2);
		fdf_free(data);
	}
}

int				main(int ac, char **av)
{
	t_data *data;

	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		fdf_free(data);
	check_args(ac, data);
	initialize(data);
	parsing_av(av[1], data);
	read_av(av[1], data);
	reprint_scope(data);
	if (!error_checker(ac))
		fdf_free(data);
	data->window = mlx_new_window(data->mlx, WIN_W, WIN_H, "fdf");
	if (data->window == (void *)0)
		fdf_free(data);
	vector_mark(data);
	mlx_key_hook(data->window, add_keys, data);
	mlx_mouse_hook(data->window, add_mouse, data);
	mlx_hook(data->window, 17, 0, (void *)fdf_free, data);
	mlx_loop(data->mlx);
}
