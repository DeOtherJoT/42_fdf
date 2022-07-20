/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:00:42 by jthor             #+#    #+#             */
/*   Updated: 2022/07/20 19:00:48 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_del_dup(t_matrix **dup, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		ft_matrix_del(dup[i]);
		i++;
	}
	free(dup);
}

t_matrix	**ft_duplicate_coords(t_matrix **coords, size_t row, size_t col)
{
	t_matrix	**ret;
	size_t		i;

	ret = malloc(row * col * sizeof(t_matrix *));
	i = 0;
	while (i < (row * col))
	{
		ret[i] = ft_matrix_cp(coords[i]);
		i++;
	}
	return (ret);
}
