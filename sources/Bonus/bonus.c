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
		map->mod->trans_y -= 10;
	else if (key == DOWN)
		map->mod->trans_y += 10;
	else if (key == LEFT)
		map->mod->trans_x -= 10;
	else
		map->mod->trans_x += 10;
	render_bonus_img(map->data, map->img, map->mod, map);
}

/*
Implementation to alter the height of the peaks.
*/

void	bonus_peak(t_map *map, int key)
{
	if (key == PLUS)
		map->mod->scale_z *= 2;
	else
		map->mod->scale_z *= 0.5;
	render_bonus_img(map->data, map->img, map->mod, map);
}

/*
Implementation to alter the scale of the x-y plane.
*/

void	bonus_scale(t_map *map, int key)
{
	if (key == K_B)
	{
		map->mod->scale_x *= 2;
		map->mod->scale_y *= 2;
	}
	else if (key == K_N)
		map->mod->scale_x *= 2;
	else if (key == K_M)
		map->mod->scale_y *= 2;
	else if (key == K_X)
		map->mod->scale_x *= 0.5;
	else if (key == K_C)
		map->mod->scale_y *= 0.5;
	else
	{
		map->mod->scale_x *= 0.5;
		map->mod->scale_y *= 0.5;
	}
	render_bonus_img(map->data, map->img, map->mod, map);
}

/*
Implementation to rotate the map
*/

void	bonus_rotate(t_map *map, int key)
{
	if (key == K_I)
		map->mod->rot_x += 10;
	else if (key == K_O)
		map->mod->rot_y += 10;
	else if (key == K_P)
		map->mod->rot_z += 10;
	else if (key == K_J)
		map->mod->rot_x -= 10;
	else if (key == K_K)
		map->mod->rot_y -= 10;
	else if (key == K_L)
		map->mod->rot_z -= 10;
	render_bonus_img(map->data, map->img, map->mod, map);
}

/*
Implementation to reset to isometric projection
*/

void	bonus_reset(t_map *map)
{
	free(map->mod);
	map->mod = iso_init(map->row * map->col);
	render_first_img(map->data, map->img, map->mod, map);
}
