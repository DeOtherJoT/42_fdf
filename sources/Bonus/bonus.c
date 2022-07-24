/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:46:00 by jthor             #+#    #+#             */
/*   Updated: 2022/07/20 18:47:13 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

/*
Implementation to translate the map along the screen.
*/
void	bonus_translate(t_map *map, int key)
{
	if (key == UP)
		ft_matrix_translate(map->trans_late, 0, -10, 0);
	else if (key == DOWN)
		ft_matrix_translate(map->trans_late, 0, 10, 0);
	else if (key == LEFT)
		ft_matrix_translate(map->trans_late, -10, 0, 0);
	else
		ft_matrix_translate(map->trans_late, 10, 0, 0);
	render_bonus_img(map->data, map->img, map);
}

/*
Implementation to alter the height of the peaks.
*/

void	bonus_peak(t_map *map, int key)
{
	if (key == PLUS)
		ft_matrix_scale(map->trans_scale, 1, 1, 2);
	else
		ft_matrix_scale(map->trans_scale, 1, 1, 0.5);
	render_bonus_img(map->data, map->img, map);
}

/*
Implementation to alter the scale of the x-y plane.
*/

void	bonus_scale(t_map *map, int key)
{
	if (key == K_B)
		ft_matrix_scale(map->trans_scale, 2, 2, 1);
	else if (key == K_N)
		ft_matrix_scale(map->trans_scale, 2, 1, 1);
	else if (key == K_M)
		ft_matrix_scale(map->trans_scale, 1, 2, 1);
	else if (key == K_X)
		ft_matrix_scale(map->trans_scale, 0.5, 1, 1);
	else if (key == K_C)
		ft_matrix_scale(map->trans_scale, 1, 0.5, 1);
	else
		ft_matrix_scale(map->trans_scale, 0.5, 0.5, 1);
	render_bonus_img(map->data, map->img, map);
}

/*
Implementation to rotate the map
*/

void	bonus_rotate(t_map *map, int key)
{
	if (key == K_I)
		ft_matrix_rotate_x(map->trans_rot, 10);
	else if (key == K_O)
		ft_matrix_rotate_y(map->trans_rot, 10);
	else if (key == K_P)
		ft_matrix_rotate_z(map->trans_rot, 10);
	else if (key == K_J)
		ft_matrix_rotate_x(map->trans_rot, -10);
	else if (key == K_K)
		ft_matrix_rotate_y(map->trans_rot, -10);
	else if (key == K_L)
		ft_matrix_rotate_z(map->trans_rot, -10);
	render_bonus_img(map->data, map->img, map);
}

/*
Implementation to reset to isometric projection
*/

void	bonus_reset(t_map *map)
{
	ft_matrix_del(map->trans_scale);
	ft_matrix_del(map->trans_rot);
	ft_matrix_del(map->trans_late);
	render_first_img(map->data, map->img, map);
}
