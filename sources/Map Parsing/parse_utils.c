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

void	ft_translate_origin(t_matrix *coord, double x, double y, double z)
{
	t_matrix	*multiplier;

	multiplier = ft_matrix_ident(4);
	ft_matrix_set(multiplier, 0, 3, x);
	ft_matrix_set(multiplier, 1, 3, y);
	ft_matrix_set(multiplier, 2, 3, z);
	ft_matrix_mult_swp2(coord, multiplier);
	ft_matrix_del(multiplier);
}

void	get_centre(t_map *map, t_matrix **coords)
{
	size_t	row;
	size_t	col;
	size_t	index;

	row = map->row;
	col = map->col;
	index = (row * col) - 1;
	map->mid_x = ft_matrix_get(coords[index], 0, 0) / 2;
	map->mid_y = ft_matrix_get(coords[index], 1, 0) / 2;
}

void	centre_origin(t_map *map, double mid_x, double mid_y)
{
	size_t	i;

	i = 0;
	while (i < (map->row * map->col))
	{
		ft_translate_origin(map->coord[i], (mid_x * -1), (mid_y * -1), 0);
		i++;
	}
}