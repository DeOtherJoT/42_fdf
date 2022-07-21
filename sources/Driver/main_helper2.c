#include "../../includes/fdf.h"

t_matrix	*ft_get_trans(t_map *map, int row, int col)
{
	t_matrix	*ret;

	ret = ft_matrix_cp(map->coord[col + (row * map->col)]);
	ft_matrix_mult_swp2(ret, map->trans_scale);
	ft_matrix_mult_swp2(ret, map->trans_rot);
	ft_matrix_mult_swp2(ret, map->trans_late);
	return (ret);
}

t_matrix	**ft_get_mats(t_map *map, int i, int j)
{
	t_matrix	**ret;

	ret = malloc(sizeof(t_matrix *) * 3);
	ret[0] = ft_get_trans(map, i, j);
	if (j < (int)(map->col - 1))
		ret[1] = ft_get_trans(map, i, j + 1);
	else
		ret[1] = ft_matrix_ident(2);
	if (i < (int)(map->row - 1))
		ret[2] = ft_get_trans(map, i + 1, j);
	else
		ret[2] = ft_matrix_ident(2);
	return (ret);
}

void	ft_del_mats(t_matrix **mat_arr)
{
	ft_matrix_del(mat_arr[0]);
	ft_matrix_del(mat_arr[1]);
	ft_matrix_del(mat_arr[2]);
}

void	plot_map(t_map *map, t_img *img)
{
	int			i;
	int			j;
	t_matrix	**mat_arr;

	i = -1;
	while (i++ < (int)map->row)
	{
		j = -1;
		while (j++ < (int)map->col)
		{
			mat_arr = ft_get_mats(map, i, j);
			if (j != (int)(map->col - 1))
				plot_line(mat_arr[0], mat_arr[1], img);
			if (i != (int)(map->row - 1))
				plot_line(mat_arr[0], mat_arr[2], img);
			ft_del_mats(mat_arr);
		}
	}
}