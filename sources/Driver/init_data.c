#include "../../includes/fdf.h"

t_data	*ft_data_new(void)
{
	t_data	*ret;

	ret = malloc(sizeof(t_data));
	ret->mlx_ptr = mlx_init();
	ret->win_ptr = mlx_new_window(ret->mlx_ptr, 1080, 1080, "FDF");
	return (ret);
}

t_img	*ft_img_new(t_data *data)
{
	t_img	*ret;

	ret = malloc(sizeof(t_img));
	data->img_ptr = mlx_new_image(data->mlx_ptr, 1080, 1080);
	ret->addr = mlx_get_data_addr(data->img_ptr,
					&ret->bpp, &ret->len, &ret->end);
	return (ret);
}

void	ft_img_del(t_img *img, t_data *data)
{
	free(data->img_ptr);
	free(img->addr);
}