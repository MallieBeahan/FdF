/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 15:19:02 by mbeahan           #+#    #+#             */
/*   Updated: 2019/09/23 19:54:40 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void initialize(t_data *data)
{
    if (!((data->mlx = mlx_init()) == (void *)0))
    {
        free(data);
        ft_putstr_fd("MLX Error.", 2);
        exit(0);
    }
    data->scope.x = 30;
    data->scope.y = -30;
    data->position.x = 400;
    data->position.y = 400;
    data->color = 0xFFFFFF;
}

static void		recalc_scale(t_data *e)
{
	while (e->scope.x * e->width > WIN_H && e->scope.x > 0)
		e->scope.x -= 1;
	while (e->scope.y * e->height < -WIN_W && e->scope.y < 0)
		e->scope.y += 1;
	if (ft_abs(e->scope.x) < ft_abs(e->scope.y))
		e->scope.y = -(e->scope.x);
	else
		e->scope.x = -(e->scope.y);
}

static int error_checker(int ac, t_data *data)
{
    if (ac != 2)
    {
        free(data);
        ft_putstr_fd("Wrong argument's number.\n", 2);
        return (0);
    }
    return (1);
}

void			add_pixel(t_data *data, int x, int y, int color)
{
	mlx_pixel_put(data->mlx, data->window, data->position.x + x, data->position.y + y, color);
}

int main (int ac, char **av)
{
    t_data *data;

    if (!(data = (t_data *)malloc(sizeof(t_data))))
        return (0);
    if (!(error_checker(ac, data)))
        return (0);
    return (1);
    initialize(data);
    parsing_av(av[1], data);
    read_av(av[1], data);
    data->window = mlx_new_window(data->mlx, WIN_H, WIN_W, "FDF");
    if (data->window == (void *)0)
        return(0); //должен быть вывод ошибки!
    vector_mark(data);
    mlx_key_hook(data->window, add_keys, data);
    mlx_mouse_hook(data->window, add_mouse, data);
    mlx_loop(data->mlx);
}