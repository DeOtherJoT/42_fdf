/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:09:18 by jthor             #+#    #+#             */
/*   Updated: 2022/07/20 19:09:40 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

/*
Allocates and returns an identity matrix that is size * size.
*/

t_matrix	*ft_matrix_ident(size_t size)
{
	t_matrix	*ret;
	size_t		i;

	if (size == 0)
		err_msg("Error at ft_matrix_ident() : size cannot be 0");
	ret = ft_matrix_new(size, size);
	i = 0;
	while (i < size)
	{
		ft_matrix_set(ret, i, i, 1);
		i++;
	}
	return (ret);
}

/*
Swaps two the two matrices passed as parameters.
*/

void	ft_matrix_swap(t_matrix *matA, t_matrix *matB)
{
	double	*temp_data;
	size_t	temp_row;
	size_t	temp_col;

	temp_row = matA->row;
	temp_col = matA->col;
	temp_data = matA->matrix;
	matA->row = matB->row;
	matA->col = matB->col;
	matA->matrix = matB->matrix;
	matB->row = temp_row;
	matB->col = temp_col;
	matB->matrix = temp_data;
}

/*
Multiplies the two matrices and returns the result as its own matrix.
*/

t_matrix	*ft_matrix_mult(t_matrix *matA, t_matrix *matB)
{
	t_matrix	*ret;
	size_t		i;
	size_t		j;
	float		temp_val;

	if (matA->col != matB->row)
		err_msg("Two matrices cannot be multiplied");
	ret = ft_matrix_new(matA->row, matB->col);
	i = 0;
	while (i < (ret->row * ret->col))
	{
		temp_val = 0;
		j = 0;
		while (j < matA->col)
		{
			temp_val += ft_matrix_get(matA, i / ret->col, j)
				* ft_matrix_get(matB, j, i % ret->col);
			j++;
		}
		ft_matrix_set(ret, i / ret->col, i % ret->col, temp_val);
		i++;
	}
	return (ret);
}

/*
Combining both ft_matrix_mult and ft_matrix_swap to get a
right-multiply function.
*/

void	ft_matrix_mult_swp(t_matrix *result, t_matrix *multiplier)
{
	t_matrix	*temp;

	temp = ft_matrix_mult(result, multiplier);
	ft_matrix_swap(temp, result);
	ft_matrix_del(temp);
}

/*
Combining both ft_matrix_mult and ft_matrix_swap to get a
left-multiply function.
*/

void	ft_matrix_mult_swp2(t_matrix *result, t_matrix *multiplier)
{
	t_matrix	*temp;

	temp = ft_matrix_mult(multiplier, result);
	ft_matrix_swap(temp, result);
	ft_matrix_del(temp);
}
