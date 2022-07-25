/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:02:18 by jthor             #+#    #+#             */
/*   Updated: 2022/07/20 19:02:19 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

/*
Frees an array previously allocated by ft_split.
*/

void	ft_free_array(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

/*
Sets the coordinates by providing an (x, y) and placing the altitude as z.
*/

t_matrix	*ft_set_coords(int i, t_map *map, char **split)
{
	t_matrix	*ret;

	ret = ft_matrix_new(4, 1);
	ret->matrix[0] = (i % map->col) - (double)(map->col / 2);
	ret->matrix[1] = (i / map->col) - (double)(map->row / 2);
	ret->matrix[2] = ft_atoi(split[i % map->col]);
	ret->matrix[3] = 1;
	return (ret);
}
