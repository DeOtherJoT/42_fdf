/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:00:04 by jthor             #+#    #+#             */
/*   Updated: 2022/07/20 19:00:07 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

/*
Closes the program when called. Only used in two situations :-
1. When the ESC key is pressed.
2. When the window exit button (x) is pressed.
*/

int	close_prog(void)
{
	write(1, "Program closed\n", 15);
	exit(EXIT_SUCCESS);
	return (1);
}

/*
Implementation for the bonus section. Called when a key is pressed.
The function checks whether the key matches those which are reserved with
an intended purpose and calls the function associated to it.
*/

int	ft_handle_key(int key, t_map *map_data)
{
	ft_img_refresh(map_data);
	if (key == ESC)
		close_prog();
	else if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		bonus_translate(map_data, key);
	else if (key == PLUS || key == MINUS)
		bonus_peak(map_data, key);
	else if (key == K_B || key == K_N || key == K_M || key == K_Z
		|| key == K_X || key == K_C)
		bonus_scale(map_data, key);
	else if (key == K_DEL)
		bonus_reset(map_data);
	else
		bonus_rotate(map_data, key);
	return (0);
}

/*
Renders the first image by transforming the coordinates to points on an image
instance and connecting them pixel by pixel to form the isometric projection.
The image is then pushed to the window to be viewed.
*/

void	render_first_img(t_data *data, t_img *img, t_mod *mod, t_map *map)
{
	ft_trans_refresh(map, 0);
	ft_matrix_scale(map->trans_rot, mod->scale_x, mod->scale_y, mod->scale_z);
	ft_matrix_rotate_z(map->trans_rot, mod->rot_z);
	ft_matrix_rotate_x(map->trans_rot, mod->rot_x);
	ft_matrix_translate(map->trans_late, 960, 540, 0);
	plot_map(map, img);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img_ptr, 0, 0);
}

/*
This fdf program is split to three main parts :-

1)	The .fdf file is parsed into a map instance where the coordinates are
	centered about (0,0).
2)	The image is rendered by multiplying each coordinate by the
	transformation matrix and plotting them onto the image. Note that the
	original coordinates are not updated after multiplication. This image is
	then pushed to the window.
3)	If the appropriate key is pressed, update the transformation matrix, create
	a new image instance and plot it with the updated projected coordinates.
	The window is cleared and the new image is pushed to it.
*/

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		err_msg("Incorrect number of arguments.");
	map = parse_map(argv[1]);
	map->data = ft_data_new();
	map->img = ft_img_new(map->data);
	render_first_img(map->data, map->img, map->mod, map);
	mlx_key_hook(map->data->win_ptr, ft_handle_key, map);
	mlx_hook(map->data->win_ptr, 17, 0, close_prog, 0);
	mlx_loop(map->data->mlx_ptr);
}
