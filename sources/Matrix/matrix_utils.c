#include "../../includes/fdf.h"

t_matrix	*ft_matrix_cp(t_matrix *mat)
{
	t_matrix	*ret;
	size_t		i;
	size_t		j;

	ret = malloc(sizeof(t_matrix));
	ret->col = mat->col;
	ret->row = mat->row;
	i = 0;
	j = 0;
	
	return (ret);
}