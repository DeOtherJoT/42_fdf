#include "../../includes/fdf.h"

int	close_prog(void)
{
	write(1, "Program closed\n", 15);
	exit(EXIT_SUCCESS);
	return (1);
}

int	ft_handle_key(int key, t_map *map_data)
{
	(void)map_data;
	if (key == ESC)
		close_prog();
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		bonus_translate(map_data);
	if (key == PLUS || key == MINUS)
		bonus_scale(map_data);
	else
		bonus_rotate(map_data);
	return (0);
}

void	render_first_img(t_data *data, t_img *img, t_map *map)
{
	map->trans_rot = ft_matrix_ident(4);
	map->trans_late = ft_matrix_ident(4);
	ft_matrix_rotate_z(map->trans_rot, map->mod->rot_z);
	ft_matrix_rotate_x(map->trans_rot, map->mod->rot_x);
	ft_matrix_translate(map->trans_late, map->mod->trans_x,
							map->mod->trans_y, 0);
	plot_map(map, img);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
								data->img_ptr, 0, 0);
	ft_img_del(img, data);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		err_msg("Incorrect number of arguments.");
	map = parse_map(argv[1]);
	map->data = ft_data_new();
	map->img = ft_img_new(map->data);
	render_first_img(map->data, map->img, map);
	mlx_key_hook(map->data->win_ptr, ft_handle_key, map);
	mlx_hook(map->data->win_ptr, 17, 0, close_prog, 0);
	mlx_loop(map->data->mlx_ptr);
}