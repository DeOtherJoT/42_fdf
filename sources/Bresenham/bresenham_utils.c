#include "../../includes/fdf.h"

int	ft_abs(double x)
{
	if (x < 0)
		return (x * -1);
	return (x);
}

void	plot_pixel(int x, int y, t_img *img)
{
	char	*dst;
	int		offset;

	offset = y * img->len + x * (img->bpp / 8);
	dst = img->addr + offset;
	*(unsigned int *)dst = 0x000000FF;
}