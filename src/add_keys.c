/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 17:48:38 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/09/23 18:32:21 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int     add_keys(int num_button, t_data *data)
{
    if (num_button == MAIN_PAD_ESC)
        exit(0);
    if (num_button == ARROW_RIGHT)
        data->position.x += 20;
    if (num_button == ARROW_LEFT)
        data->position.x -= 20;
    if (num_button == ARROW_DOWN)
        data->position.y += 20;
    if (num_button == ARROW_UP)
        data->position.y -= 20;
    if (num_button == NUM_PAD_PLUS)
        data->scope.x += 1;
        data->scope.y -= 1;
    if (num_button == NUM_PAD_MINUS)
        data->scope.x -= 1;
        data->scope.y += 1;
    //zdes nado risovat || net, hz| need to think
    return(1);
}