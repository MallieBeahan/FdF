/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_av.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:50:17 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/09/23 18:12:16 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void     find_small_matrix(t_data *data, int x, int y, int c)
{
    size_t  tmp;

    if (c == 0){
        tmp = ft_abs(data->matrix[x][y].z);
        if (!data->small && tmp != 0 || (data->small > tmp && tmp != 0))
            data->small = tmp;
    }
    else
    {
        if (!data->small)
            data->small = 1;
        while (y < data->height){
            while (x < data->width){
                data->matrix[y][x].z /= data->small;
                data->matrix[y][x].z0 /= data->small;
                x++;
            }
            x = 0;
            y++;
        }
    }
}

void    read_av(char *fp, t_data *data)
{
    int fd;
    int x;
    int y;
    char *ln;
    char **split;

    x = 0;
    y = 0;
    fd = open(fp, O_RDONLY);
    while (get_next_line(fd, &ln) > 0)
    {
        split = ft_strsplit(ln, ' ');
        while (split != 0)
        {
            data->matrix[x][y].z = ft_atoi(*split);
            find_small_matrix(data, x, y, 0);
            data->matrix[y][x].z0 = data->matrix[y][x].z;
            x++;
            split++;
        }
        x = 0;
        y++;
    }
    close(fd);
    find_small_matrix(data, 0, 0, 1);
}