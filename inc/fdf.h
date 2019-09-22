/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 15:20:07 by mbeahan           #+#    #+#             */
/*   Updated: 2019/09/22 17:20:46 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
#include "../libft/includes/libft.h"

typedef struct	s_pixel
{
	int	x;
	int	y;
}				t_pixel;

typedef struct	s_data
{
	void	*mlx;
	void	*window;
	t_pixel	position;
	t_pixel	size;
	int		width;
	int		height;
	int		color;

}				t_data;

#endif
