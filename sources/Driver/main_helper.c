/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:00:28 by jthor             #+#    #+#             */
/*   Updated: 2022/07/20 19:00:31 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

/*
Take the duplicated coordinates centered about (0,0) and transforms them
according to the set transformation matrix.
*/

void	transform_coord(t_matrix **coords, t_map *map, size_t n)
{
	t_matrix	*total_trans;
	size_t		i;

	total_trans = get_total_trans(map->trans_scale, map->trans_rot,
			map->trans_late);
	i = -1;
	while (++i < n)
		ft_matrix_mult_swp2(coords[i], total_trans);
	ft_matrix_del(total_trans);
}

/*
Gets a single coordinate from the duplicated coordinate array.
*/

t_matrix	*ft_coord_get(t_map *map, t_matrix **dup, int row, int col)
{
	return (dup[col + (row * map->col)]);
}

/*
Takes the coordinates that are centered about (0,0), duplicates them,
and transforms the duplicated coords. These transformed duplicates are
then used to plot the projection onto the image instance.
*/

void	plot_map(t_map *map, t_img *img)
{
	t_matrix	**temp;
	size_t		i;
	size_t		j;

	temp = ft_duplicate_coords(map->coord, map->row, map->col);
	transform_coord(temp, map, (map->row * map->col));
	i = -1;
	while (++i < map->row)
	{
		j = -1;
		while (++j < map->col)
		{
			if (j != (map->col - 1))
				plot_line(ft_coord_get(map, temp, i, j),
					ft_coord_get(map, temp, i, j + 1), img);
			if (i != (map->row - 1))
				plot_line(ft_coord_get(map, temp, i, j),
					ft_coord_get(map, temp, i + 1, j), img);
		}
	}
	ft_del_dup(temp, (map->row * map->col));
}
