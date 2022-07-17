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
	size_t	k;
	size_t	col;
	size_t	row;

	i = 0;
	k = 0;
	col = map->col;
	row = map->row;
	while (i < (row * col))
	{
		if ((i % col) + 1 != col)
			plot_line(dup[(i % col) + k], dup[(i % col) + 1 + k], img);
		else
			k += col;
		i++;
	}
}

void	plot_cols(t_map *map, t_matrix **dup, t_img *img)
{
	size_t	i;
	size_t	k;
	size_t	col;
	size_t	row;

	i = 0;
	k = 0;
	col = map->col;
	row = map->row;
	while (i < ((row - 1) * col))
	{
		if ((i % col) + 1 != col)
			plot_line(dup[(i % col) + k], dup[(i % col) + col + k], img);
		else
			k += col;
		i++;
	}
}

void	plot_map(t_map *map, t_img *img)
{
	t_matrix	**temp;

	temp = ft_duplicate_coords(map->coord, map->row, map->col);
	transform_coord(temp, map->trans_matrix, (map->row * map->col));
	plot_rows(map, temp, img);
	plot_cols(map, temp, img);
	ft_del_dup(temp, (map->row * map->col));
}