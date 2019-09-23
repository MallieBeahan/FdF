/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 17:48:38 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/09/23 18:03:09 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     add_keys(int keycode, t_data *data)
{
    if (keycode == MAIN_PAD_ESC)
        exit(0);
    if (keycode == ARROW_RIGHT)
        data->position.x += 20;
    if (keycode == ARROW_LEFT)
        data->position.x -= 20;
    if (keycode == ARROW_DOWN)
        data->position.y += 20;
    if (keycode == ARROW_UP)
        data->position.y -= 20;
    if (keycode == NUM_PAD_PLUS)
        data->scope.x += 1;
        data->scope.y -= 1;
    if (keycode == NUM_PAD_MINUS)
        data->scope.x -= 1;
        data->scope.y += 1;
    //zdes nado risovat || net, hz| need to think
    return(1);
}