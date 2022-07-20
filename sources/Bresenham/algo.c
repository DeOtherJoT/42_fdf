/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:56:06 by jthor             #+#    #+#             */
/*   Updated: 2022/07/20 18:56:11 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

/*
This file contains code taken (and translated) from Wikipedia's page on
Bresenham's Line Algorithm.
https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
*/

void	plot_line_low(int setA[2], int setB[2], t_img *img)
{
	t_bla	dat;

	dat.dx = setB[0] - setA[0];
	dat.dy = setB[1] - setA[1];
	dat.const_i = 1;
	if (dat.dy < 0)
	{
		dat.const_i *= -1;
		dat.dy *= -1;
	}
	dat.var_d = (2 * dat.dy) - dat.dx;
	while (setA[0] != setB[0])
	{
		plot_pixel(setA[0], setA[1], img);
		if (dat.var_d > 0)
		{
			setA[1] += dat.const_i;
			dat.var_d += (2 * (dat.dy - dat.dx));
		}
		else
			dat.var_d += (2 * dat.dy);
		setA[0] += 1;
	}
	plot_pixel(setA[0], setA[1], img);
}

void	plot_line_high(int setA[2], int setB[2], t_img *img)
{
	t_bla	dat;

	dat.dx = setB[0] - setA[0];
	dat.dy = setB[1] - setA[1];
	dat.const_i = 1;
	if (dat.dx < 0)
	{
		dat.const_i *= -1;
		dat.dx *= -1;
	}
	dat.var_d = (2 * dat.dx) - dat.dy;
	while (setA[1] != setB[1])
	{
		plot_pixel(setA[0], setA[1], img);
		if (dat.var_d > 0)
		{
			setA[0] += dat.const_i;
			dat.var_d += (2 * (dat.dx - dat.dy));
		}
		else
			dat.var_d += (2 * dat.dx);
		setA[1] += 1;
	}
	plot_pixel(setA[0], setA[1], img);
}

void	plot_line(t_matrix *matA, t_matrix *matB, t_img *img)
{
	t_coord	*coord;
	int		abs_dy;
	int		abs_dx;

	coord = ft_coords_new(matA, matB);
	abs_dy = ft_abs(coord->set1[1] - coord->set0[1]);
	abs_dx = ft_abs(coord->set1[0] - coord->set0[0]);
	if (abs_dy < abs_dx)
	{
		if (coord->set0[0] > coord->set1[0])
			plot_line_low(coord->set1, coord->set0, img);
		else
			plot_line_low(coord->set0, coord->set1, img);
	}
	else
	{
		if (coord->set0[1] > coord->set1[1])
			plot_line_high(coord->set1, coord->set0, img);
		else
			plot_line_high(coord->set0, coord->set1, img);
	}
	ft_coords_del(coord);
}
