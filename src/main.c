/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 15:19:02 by mbeahan           #+#    #+#             */
/*   Updated: 2019/09/22 15:42:49 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static error_checker(int ac, t_data *data)
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
}