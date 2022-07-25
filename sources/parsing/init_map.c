/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:01:32 by jthor             #+#    #+#             */
/*   Updated: 2022/07/20 19:01:33 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

/*
This file contains the constructor and destructor for the struct t_map.
*/

t_map	*ft_map_new(size_t row, size_t col)
{
	t_map	*ret;

	ret = malloc(sizeof(t_map));
	if (ret == 0)
		err_msg("Error at ft_map_new()");
	ret->row = row;
	ret->col = col;
	ret->coord = malloc(row * col * sizeof(t_matrix *));
	if (!ret->coord)
		err_msg("Malloc error : Coordinate matrix");
	return (ret);
}

void	ft_map_del(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < (map->row * map->col))
	{
		free(map->coord[i]);
		i++;
	}
	free(map->coord);
	ft_matrix_del(map->trans_rot);
	ft_matrix_del(map->trans_late);
}
