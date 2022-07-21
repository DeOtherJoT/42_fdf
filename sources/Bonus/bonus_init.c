/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:49:19 by jthor             #+#    #+#             */
/*   Updated: 2022/07/20 18:49:24 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

ssize_t	ft_decide_scale(size_t size)
{
	if (size <= 1000)
		return (50);
	else if (size <= 5000)
		return (25);
	else if (size <= 7500)
		return (10);
	else if (size <= 10000)
		return (5);
	else
		return (3);
}

ssize_t	ft_decide_peak(size_t size)
{
	if (size <= 100)
		return (5);
	else if (size <= 500)
		return (4);
	else if (size <= 1000)
		return (3);
	else if (size <= 5000)
		return (2);
	else
		return (1);
}

t_mod	*iso_init(size_t size)
{
	t_mod	*ret;

	ret = malloc(sizeof(t_mod));
	if (!ret)
		err_msg("Failed at ft_iso_init");
	ret->scale_i = ft_decide_scale(size);
	ret->scale_x = 1;
	ret->scale_y = 1;
	ret->scale_z = 1;
	ret->peak = ft_decide_peak(size);
	ret->rot_x = 54.736;
	ret->rot_z = 45;
	ret->rot_y = 0;
	ret->trans_x = 960;
	ret->trans_y = 540;
	return (ret);
}
