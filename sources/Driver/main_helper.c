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

void	transform_coord(t_matrix **coords, t_matrix *trans_matrix, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		ft_matrix_mult_swp2(coords[i], trans_matrix);
		i++;
	}
}

void	plot_rows(t_map *map, t_matrix **dup, t_img *img)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < (map->col - 1))
		{
			plot_line(ft_coord_get(map, dup, i, j),
				ft_coord_get(map, dup, i, j + 1), img);
			j++;
		}
		i++;
	}
}

void	plot_cols(t_map *map, t_matrix **dup, t_img *img)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < (map->row - 1))
	{
		j = 0;
		while (j < (map->col))
		{
			plot_line(ft_coord_get(map, dup, i, j),
				ft_coord_get(map, dup, i + 1, j), img);
			j++;
		}
		i++;
	}
}

void	plot_map_iso(t_map *map, t_img *img)
{
	t_matrix	**temp;

	temp = ft_duplicate_coords(map->coord, map->row, map->col);
	transform_coord(temp, map->trans_rot, (map->row * map->col));
	transform_coord(temp, map->trans_late, (map->row * map->col));
	plot_rows(map, temp, img);
	plot_cols(map, temp, img);
	ft_del_dup(temp, (map->row * map->col));
}
