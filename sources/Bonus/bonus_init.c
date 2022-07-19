#include "../../includes/fdf.h"

ssize_t	ft_decide_scale(size_t size)
{
	if (size < 100)
		return (75);
	else if (size < 500)
		return (50);
	else if (size < 1000)
		return (25);
	else
		return (10);
}

t_mod	*iso_init(size_t size)
{
	t_mod	*ret;

	ret = malloc(sizeof(t_mod));
	if (!ret)
		err_msg("Failed at ft_iso_init");
	ret->scale = ft_decide_scale(size);
	ret->peak = 10;
	ret->rot_x = 90 - 35.264;
	ret->rot_z = 45;
	ret->rot_y = 0;
	ret->trans_x = 960;
	ret->trans_y = 540;
	return (ret);
}