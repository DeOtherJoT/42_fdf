#include "../../includes/fdf.h"

/*
Helper function that returns the absolute value of the parameter x.
*/

int	ft_abs(double x)
{
	if (x < 0)
		return (x * -1);
	return (x);
}

/*
Function that utilises the minilibx library to plot a pixel to an image
instead of to the window for optimisation.
*/

void	plot_pixel(int x, int y, t_img *img)
{
	char	*dst;
	int		offset;

	if (x > 0 && y > 0 && x < SCR_WIDTH && y < SCR_HEIGHT)
	{
		offset = y * img->len + x * (img->bpp / 8);
		dst = img->addr + offset;
		*(unsigned int *)dst = 0x0000FF00;
	}
}