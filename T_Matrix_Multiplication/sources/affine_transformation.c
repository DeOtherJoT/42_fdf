#include "../includes/my_matrix.h"

void    ft_matrix_translate(t_matrix *trans, double x, double y, double z)
{
    t_matrix    *multiplier;

    multiplier = ft_matrix_ident(4);
    ft_matrix_set(multiplier, 0, 3, x);
    ft_matrix_set(multiplier, 1, 3, y);
    ft_matrix_set(multiplier, 2, 3, z);
    ft_matrix_mult_swp(trans, multiplier);
    ft_matrix_del(multiplier);
}

void    ft_matrix_scale(t_matrix *trans, double x, double y, double z)
{
    t_matrix    *multiplier;

    multiplier = ft_matrix_ident(4);
    ft_matrix_set(multiplier, 0, 0, x);
    ft_matrix_set(multiplier, 1, 1, y);
    ft_matrix_set(multiplier, 2, 2, z);
    ft_matrix_mult_swp(trans, multiplier);
    ft_matrix_del(multiplier);
}

void    ft_matrix_shear(t_matrix *trans, double x, double y, double z)
{
    t_matrix    *multiplier;

    multiplier = ft_matrix_ident(4);
    ft_matrix_set(multiplier, 0, 1, x * y);
    ft_matrix_set(multiplier, 0, 2, x * z);
    ft_matrix_set(multiplier, 1, 0, y * x);
    ft_matrix_set(multiplier, 1, 2, y * z);
    ft_matrix_set(multiplier, 2, 0, z * x);
    ft_matrix_set(multiplier, 2, 1, z * y);
    ft_matrix_mult_swp(trans, multiplier);
    ft_matrix_del(multiplier);
}

