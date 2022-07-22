/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_coord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:57:23 by jthor             #+#    #+#             */
/*   Updated: 2022/07/20 18:57:25 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

/*
This file contains the cnstructor and destructor for the t_coord struct,
used to group two (x,y) coordinate sets for the Bresenham Line Algorithm
to use.
*/

t_coord	*ft_coords_new(t_matrix *matA, t_matrix *matB)
{
	t_coord	*ret;

	ret = malloc(sizeof(t_coord));
	ret->set0[0] = ft_matrix_get(matA, 0, 0);
	ret->set0[1] = ft_matrix_get(matA, 1, 0);
	ret->set1[0] = ft_matrix_get(matB, 0, 0);
	ret->set1[1] = ft_matrix_get(matB, 1, 0);
	return (ret);
}

void	ft_coords_del(t_coord *coord)
{
	free(coord);
}
