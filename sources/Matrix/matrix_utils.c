#include "../../includes/fdf.h"

t_matrix	*ft_matrix_cp(t_matrix *mat)
{
	t_matrix	*ret;

	ret = ft_matrix_create(mat->row, mat->col, mat->matrix);
	return (ret);
}