/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affine_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:05:09 by jthor             #+#    #+#             */
/*   Updated: 2022/07/20 19:05:11 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

/*
Helper function that converts the parameter deg in degrees and converts it to
its radian equivalent.
*/

double	ft_deg_to_rad(double deg)
{
	return (deg * (M_PI / 180));
}

/*
Functions that applies the respective rotations to the trans parameter and
updates it.
*/

void	ft_matrix_rotate_x(t_matrix *trans, double x)
{
	t_matrix	*multiplier;
	double		rad;

	rad = ft_deg_to_rad(x);
	multiplier = ft_matrix_ident(4);
	ft_matrix_set(multiplier, 1, 1, cos(rad));
	ft_matrix_set(multiplier, 1, 2, -sin(rad));
	ft_matrix_set(multiplier, 2, 1, sin(rad));
	ft_matrix_set(multiplier, 2, 2, cos(rad));
	ft_matrix_mult_swp2(trans, multiplier);
	ft_matrix_del(multiplier);
}

void	ft_matrix_rotate_y(t_matrix *trans, double y)
{
	t_matrix	*multiplier;
	double		rad;

	rad = ft_deg_to_rad(y);
	multiplier = ft_matrix_ident(4);
	ft_matrix_set(multiplier, 0, 0, cos(rad));
	ft_matrix_set(multiplier, 0, 2, sin(rad));
	ft_matrix_set(multiplier, 2, 0, -sin(rad));
	ft_matrix_set(multiplier, 2, 2, cos(rad));
	ft_matrix_mult_swp2(trans, multiplier);
	ft_matrix_del(multiplier);
}

void	ft_matrix_rotate_z(t_matrix *trans, double z)
{
	t_matrix	*multiplier;
	double		rad;

	rad = ft_deg_to_rad(z);
	multiplier = ft_matrix_ident(4);
	ft_matrix_set(multiplier, 0, 0, cos(rad));
	ft_matrix_set(multiplier, 0, 1, -sin(rad));
	ft_matrix_set(multiplier, 1, 0, sin(rad));
	ft_matrix_set(multiplier, 1, 1, cos(rad));
	ft_matrix_mult_swp2(trans, multiplier);
	ft_matrix_del(multiplier);
}
