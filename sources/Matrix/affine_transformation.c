/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affine_transformation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:05:26 by jthor             #+#    #+#             */
/*   Updated: 2022/07/20 19:07:04 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

/*
Functions that applies the respective operations to the parameter trans and
updates it. Left multiplies the matrices.
*/

void	ft_matrix_translate(t_matrix *trans, double x, double y, double z)
{
	t_matrix	*multiplier;

	multiplier = ft_matrix_ident(4);
	ft_matrix_set(multiplier, 0, 3, x);
	ft_matrix_set(multiplier, 1, 3, y);
	ft_matrix_set(multiplier, 2, 3, z);
	ft_matrix_mult_swp2(trans, multiplier);
	ft_matrix_del(multiplier);
}

void	ft_matrix_scale(t_matrix *trans, double x, double y, double z)
{
	t_matrix	*multiplier;

	multiplier = ft_matrix_ident(4);
	ft_matrix_set(multiplier, 0, 0, x);
	ft_matrix_set(multiplier, 1, 1, y);
	ft_matrix_set(multiplier, 2, 2, z);
	ft_matrix_mult_swp2(trans, multiplier);
	ft_matrix_del(multiplier);
}

void	ft_matrix_shear(t_matrix *trans, double x, double y, double z)
{
	t_matrix	*multiplier;

	multiplier = ft_matrix_ident(4);
	ft_matrix_set(multiplier, 0, 1, x * y);
	ft_matrix_set(multiplier, 0, 2, x * z);
	ft_matrix_set(multiplier, 1, 0, y * x);
	ft_matrix_set(multiplier, 1, 2, y * z);
	ft_matrix_set(multiplier, 2, 0, z * x);
	ft_matrix_set(multiplier, 2, 1, z * y);
	ft_matrix_mult_swp2(trans, multiplier);
	ft_matrix_del(multiplier);
}

t_matrix	*get_total_trans(t_matrix *scale, t_matrix *rot, t_matrix *late)
{
	t_matrix	*ret;

	ret = ft_matrix_mult(rot, scale);
	ft_matrix_mult_swp2(ret, late);
	return (ret);
}
