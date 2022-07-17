#include "../../includes/fdf.h"

void	transform_coords(t_map *map, t_matrix *multiplier)
{
	size_t	i;

	i = 0;
	while (i < (map->row * map->col))
	{
		ft_matrix_mult_swp(map->coord[i], multiplier);
		i++;
	}
}