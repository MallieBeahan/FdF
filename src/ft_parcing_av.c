/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing_av.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 20:40:19 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/09/22 20:51:22 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int     geting_map(char *fp, int c)
{
    int     fd;
    int     ret;
    char    *ln;

    ret = 0;
    fd = open(fp, O_RDONLY);
    if (c = 1)
    {
        while (get_next_line(fd, &ln) > 0)
            ret++;
        close(fd);
    }
    else
    {
        get_next_line(fd, &ln);
        while (get_next_line)
    }
}

void    parsing_av(char *fp, t_data *data)
{
    int i;

    i = 0;
    data->graph = (t_graph **)malloc(sizeof(t_graph *) * data->height);

}