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
	ret->trans_matrix = ft_matrix_ident(4);
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
	ft_matrix_del(map->trans_matrix);
}