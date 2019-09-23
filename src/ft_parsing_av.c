/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_av.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 20:40:19 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/09/23 20:05:44 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static int     geting_matrix(char *fp, int flag)
{
    int     fd;
    int     ret;
    char    *ln;

    ret = 0;
    fd = open(fp, O_RDONLY);
    if (flag == 1)
    {
        while (get_next_line(fd, &ln) > 0)
            ret++;
        close(fd);
    }
    else
    {
        get_next_line(fd, &ln);
        ret = word_counter(ln);
        while (get_next_line(fd, &ln) > 0)
        {
            if (word_counter(ln) != ret)
                return(0);
        }
        close(fd);
    }
    return(ret);
}

int  word_counter(const char *ln)
{
    char    charend;
    int     count;
    int     i;
    int     line;

    i = 0;
    count = 0;
    line = ft_strlen(ln);
    if (line > 0)
        charend = ln[0];
    while (i <= line)
    {
        if ((ln[i] == ' ' || ln[i] == '\0') && charend != ' ')
            count++;
        charend = ln[i];
        i++;
    }
    return(count);
}

void    parsing_av(char *fp, t_data *data)
{
    int i;

    i = 0;
    data->matrix = (t_matrix **)malloc(sizeof(t_matrix *) * data->height);
    data->height = geting_matrix(fp, 1);
    data->width = geting_matrix(fp, 2);
    while(i < data->height)
    {
        data->matrix[i] = (t_matrix *)malloc(sizeof(t_matrix) * data->width);
        i++;
    }
}