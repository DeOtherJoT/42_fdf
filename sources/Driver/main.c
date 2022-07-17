#include "../../includes/fdf.h"

int	close_prog(void)
{
	write(1, "Program closed\n", 15);
	exit(EXIT_SUCCESS);
	return (1);
}

int	ft_handle_key(int keycode, t_map *map_data)
{
	if (keycode == ESC)
		return (close_prog);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_img	*img;
	t_map	*map_data;

	if (argc == 2)
		err_msg("Incorrect number of arguments.");
	data = ft_data_new();
	img = ft_img_new(data);
	map_data = parse_map(argv[1]);
	mlx_key_hook(data->win_ptr, ft_handle_key, map_data);
	mlx_hook(data->win_ptr, 17, 0, close_prog, 0);
}