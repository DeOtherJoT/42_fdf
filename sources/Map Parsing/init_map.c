#include "../../includes/fdf.h"

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

t_matrix	*ft_coord_get(t_map *map, t_matrix **dup, int row, int col)
{
	return (dup[col + (row * map->col)]);
}