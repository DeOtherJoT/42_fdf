#include "../../includes/fdf.h"

t_coord	*ft_coords_new(t_matrix *matA, t_matrix *matB)
{
	t_coord *ret;

	ret = malloc(sizeof(t_coord));
	ret->set0[0] = ft_matrix_get(matA, 0, 0);
	ret->set0[1] = ft_matrix_get(matA, 1, 0);
	ret->set1[0] = ft_matrix_get(matB, 0, 0);
	ret->set1[1] = ft_matrix_get(matB, 1, 0);
	return (ret);
}

void	ft_coords_del(t_coord *coord)
{
	free(coord);
}