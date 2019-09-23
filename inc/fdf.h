/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 15:20:07 by mbeahan           #+#    #+#             */
/*   Updated: 2019/09/23 18:24:34 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
#include "../libft/includes/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "mlx.h"
#include "keycodes.h"


# define WIN_H 1080
# define WIN_W 1920
# define WHITE 0xFFFFFF
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define PURPLE 0xFF00FF
# define ORANGE 0x0080FF

typedef struct	s_matrix
{
	int			pos_x;
	int			z;
	int			z0;
	int			pos_y;
}				t_matrix;

typedef struct	s_pixel
{
	int			x;
	int			y;
}				t_pixel;

typedef struct	s_data
{
	void		*mlx;
	void		*window;
	t_pixel		position;
	t_pixel		scope;
	int			width;
	int			height;
	int			color;
	t_matrix	**matrix;
	int			min_matrix;
	int			alltitude;

}				t_data;

void    read_av(char *fp, t_data *data);
void    parsing_av(char *fp, t_data *data);
int     add_keys(int keycode, t_data *data);

#endif
