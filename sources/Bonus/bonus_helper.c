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

void	ft_trans_init(t_map *map)
{
	map->trans_scale = ft_matrix_ident(4);
	map->trans_rot = ft_matrix_ident(4);
	map->trans_late = ft_matrix_ident(4);
}

/*
Renders an updated image after the transformation matrix is updated by a
key press. Basically does the same thing as render_first_img() from the main.c
file in the Driver folder.
*/

void	render_bonus_img(t_data *data, t_img *img, t_map *map)
{
	plot_map(map, img);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img_ptr, 0, 0);
}
