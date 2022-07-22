/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:02:18 by jthor             #+#    #+#             */
/*   Updated: 2022/07/20 19:02:19 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_free_array(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

t_matrix	*ft_set_coords(int i, t_map *map, t_mod *mod, char **split)
{
	t_matrix	*ret;

	ret = ft_matrix_new(4, 1);
	ft_matrix_set(ret, 0, 0, (i % map->col) * mod->scale_i);
	ft_matrix_set(ret, 1, 0, (i / map->col) * mod->scale_i);
	ft_matrix_set(ret, 2, 0, ft_atoi(split[i % map->col]) * mod->peak);
	ft_matrix_set(ret, 3, 0, 1);
	return (ret);
}

void	centre_origin(t_map *map, t_matrix **coords)
{
	size_t	index;
	size_t	i;
	double	mid_x;
	double	mid_y;

	index = (map->row * map->col) - 1;
	mid_x = ft_matrix_get(coords[index], 0, 0) / 2;
	mid_y = ft_matrix_get(coords[index], 1, 0) / 2;
	i = 0;
	while (i < (map->row * map->col))
	{
		ft_matrix_translate(map->coord[i], (mid_x * -1), (mid_y * -1), 0);
		i++;
	}
}
