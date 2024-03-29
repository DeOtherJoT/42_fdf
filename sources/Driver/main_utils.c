/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:00:42 by jthor             #+#    #+#             */
/*   Updated: 2022/07/20 19:00:48 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

/*
Deletes the coordinate array created by ft_duplicate_coords().
*/

void	ft_del_dup(t_matrix **dup, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		ft_matrix_del(dup[i]);
		i++;
	}
	free(dup);
}

/*
Duplicates the array of original coordinates centered around (0,0) in order
to transform them and plot them to the image without actually updating the
original coordinates.
*/

t_matrix	**ft_duplicate_coords(t_matrix **coords, size_t row, size_t col)
{
	t_matrix	**ret;
	size_t		i;

	ret = malloc(row * col * sizeof(t_matrix *));
	i = 0;
	while (i < (row * col))
	{
		ret[i] = ft_matrix_cp(coords[i]);
		i++;
	}
	return (ret);
}

/*
Function that decides how far apart two points should be based on the total
size of the map.
*/

size_t	ft_decide_scale(size_t size)
{
	if (size <= 1000)
		return (50);
	else if (size <= 5000)
		return (25);
	else if (size <= 10000)
		return (10);
	else if (size <= 50000)
		return (5);
	else
		return (3);
}

/*
Function that decides if the altitudes need to be upscaled by a set amount
based on the total size of the map.
*/

size_t	ft_decide_peak(size_t size)
{
	if (size <= 1000)
		return (5);
	else if (size <= 5000)
		return (4);
	else if (size <= 7500)
		return (3);
	else if (size <= 10000)
		return (2);
	else
		return (1);
}
