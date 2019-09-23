/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 21:21:45 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/09/22 21:21:52 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		ft_abs(int nb)
{
	unsigned int nbr;

	nbr = (nb < 0) ? (unsigned int)-nb : nb;
	return (nbr);
}
