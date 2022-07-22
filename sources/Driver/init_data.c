/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:58:15 by jthor             #+#    #+#             */
/*   Updated: 2022/07/20 18:58:36 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

/*
This file contains the constructors for the t_data and t_img structs.
*/

t_data	*ft_data_new(void)
{
	t_data	*ret;

	ret = malloc(sizeof(t_data));
	ret->mlx_ptr = mlx_init();
	ret->win_ptr = mlx_new_window(ret->mlx_ptr, SCR_WIDTH, SCR_HEIGHT, "FDF");
	return (ret);
}

t_img	*ft_img_new(t_data *data)
{
	t_img	*ret;

	ret = malloc(sizeof(t_img));
	data->img_ptr = mlx_new_image(data->mlx_ptr, SCR_WIDTH, SCR_HEIGHT);
	ret->addr = mlx_get_data_addr(data->img_ptr,
			&ret->bpp, &ret->len, &ret->end);
	return (ret);
}
