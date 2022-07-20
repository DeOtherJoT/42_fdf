/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:48:49 by jthor             #+#    #+#             */
/*   Updated: 2022/07/20 18:48:53 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

/*
Frees the current img_ptr and img->addr and create another image.
*/

void	ft_img_refresh(t_map *map)
{
	mlx_destroy_image(map->data->mlx_ptr, map->data->img_ptr);
	map->img = ft_img_new(map->data);
}

/*
Frees the transformation matrices and resets them to identity matrices.
If flag is 0  -> just initialise identity matrices.
If flag is !0 -> free matrices and reset them.
*/

void	ft_trans_refresh(t_map *map, int flag)
{
	if (flag == 0)
	{
		map->trans_rot = ft_matrix_ident(4);
		map->trans_late = ft_matrix_ident(4);
		map->trans_scale = ft_matrix_ident(4);
	}
	else
	{
		ft_matrix_del(map->trans_rot);
		ft_matrix_del(map->trans_late);
		ft_matrix_del(map->trans_scale);
		map->trans_rot = ft_matrix_ident(4);
		map->trans_late = ft_matrix_ident(4);
		map->trans_scale = ft_matrix_ident(4);
	}
}

void	render_bonus_img(t_data *data, t_img *img, t_map *map)
{
	ft_trans_refresh(map, 1);
	ft_matrix_rotate_z(map->trans_rot, map->mod->rot_z);
	ft_matrix_rotate_x(map->trans_rot, map->mod->rot_x);
	ft_matrix_rotate_y(map->trans_rot, map->mod->rot_y);
	ft_matrix_translate(map->trans_late, map->mod->trans_x,
		map->mod->trans_y, 0);
	ft_matrix_scale(map->trans_scale, map->mod->scale_x, map->mod->scale_y,
		map->mod->scale_z);
	plot_map_bonus(map, img);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img_ptr, 0, 0);
}

void	plot_map_bonus(t_map *map, t_img *img)
{
	t_matrix	**temp;

	temp = ft_duplicate_coords(map->coord, map->row, map->col);
	transform_coord(temp, map->trans_scale, (map->row * map->col));
	transform_coord(temp, map->trans_rot, (map->row * map->col));
	transform_coord(temp, map->trans_late, (map->row * map->col));
	plot_rows(map, temp, img);
	plot_cols(map, temp, img);
	ft_del_dup(temp, (map->row * map->col));
}
