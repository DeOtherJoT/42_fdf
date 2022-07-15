#include "../../includes/fdf.h"

t_data	*ft_data_new(void)
{
	t_data	*ret;

	ret->mlx_ptr = mlx_init();
	ret->win_ptr = mlx_new_window(ret->mlx_ptr, 1920, 1080, "FDF");
	ret->win_ptr = mlx_new_image(ret->mlx_ptr, 1920, 1080);
	return (ret);
}

t_img	*ft_img_new(t_data *data)
{
	t_img	*ret;

	ret->addr = mlx_get_data_addr(data->img_ptr, &ret->bpp, &ret->len, &ret->end);
	return (ret);
}