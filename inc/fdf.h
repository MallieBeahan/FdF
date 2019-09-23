/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 15:20:07 by mbeahan           #+#    #+#             */
/*   Updated: 2019/09/23 19:31:29 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
#include "../libft/includes/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "mlx.h"
#include <math.h>
#include "keycodes.h"


# define WIN_H 1080
# define WIN_W 1920
# define WHITE 0xFFFFFF
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define PURPLE 0xFF00FF
# define ORANGE 0x0080FF
# define RED 0xFF0000

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
<<<<<<< HEAD
	int			min_matrix;
=======
	size_t		min_matrix;
>>>>>>> 483b3ce13341d30929030127e1d25f419c62af49
	int			altitude;

}				t_data;

void    		read_av(char *fp, t_data *data);
void    		parsing_av(char *fp, t_data *data);
int     		add_keys(int keycode, t_data *data);
int     		add_keys(int num_button, t_data *data);
int				add_mouse(int num_button, int x, int y, t_data *data);

#endif
