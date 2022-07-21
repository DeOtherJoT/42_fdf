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

void	transform_coord(t_matrix **coords, t_map *map, size_t n, int flag)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (flag == 1)
			ft_matrix_mult_swp2(coords[i], map->trans_scale);
		ft_matrix_mult_swp2(coords[i], map->trans_rot);
		ft_matrix_mult_swp2(coords[i], map->trans_late);
		i++;
	}
}

t_matrix	*ft_coord_get(t_map *map, t_matrix **dup, int row, int col)
{
	return (dup[col + (row * map->col)]);
}

void	plot_map(t_map *map, t_img *img)
{
	t_matrix	**temp;
	size_t		i;
	size_t		j;

	temp = ft_duplicate_coords(map->coord, map->row, map->col);
	transform_coord(temp, map, (map->row * map->col), 0);
	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			if (j != (map->col - 1))
				plot_line(ft_coord_get(map, temp, i, j),
					ft_coord_get(map, temp, i, j + 1), img);
			if (i != (map->row - 1))
				plot_line(ft_coord_get(map, temp, i, j),
					ft_coord_get(map, temp, i + 1, j), img);
			j++;
		}
		i++;
	}
	ft_del_dup(temp, (map->row * map->col));
}