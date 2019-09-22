/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 15:19:02 by mbeahan           #+#    #+#             */
/*   Updated: 2019/09/22 17:41:00 by mbeahan          ###   ########.fr       */
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
    data->size.x = 30;
    data->size.y = -30;
    data->position.x = 400;
    data->position.y = 400;
    data->color = 0xFFFFFF;
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

int main (int ac, char **av)
{
    t_data *data;

    if (!(data = (t_data *)malloc(sizeof(t_data))))
        return (0);
    if (!(error_checker(ac, data)))
        return (0);
    return (1);
    initialize(data);

}