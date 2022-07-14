#include "../../includes/fdf.h"

void	plot_low(double x0, double y0, double x1, double y1)
{
	
}

void	plot_line(t_matrix *matA, t_matrix *matB)
{
	double	x0;
	double	x1;
	double	y0;
	double	y1;

	x0 = ft_matrix_get(matA, 0, 0);
	x1 = ft_matrix_get(matB, 0, 0);
	y0 = ft_amatrix_get(matA, 1, 0);
	y1 = ft_matrix_get(matB, 1, 0);
}