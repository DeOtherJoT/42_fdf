/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:07:23 by jthor             #+#    #+#             */
/*   Updated: 2022/07/20 19:07:24 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

t_matrix	*ft_matrix_cp(t_matrix *mat)
{
	t_matrix	*ret;

	ret = ft_matrix_create(mat->row, mat->col, mat->matrix);
	return (ret);
}
