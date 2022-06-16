#include "../includes/my_matrix.h"

int ft_init_matrix(size_t rows, size_t col, t_matrix *matrix)
{
    double  *ret;

    if (rows == 0 || col == 0)
        return (0);
    ret = ft_calloc(rows * col, sizeof(double));
    if (!ret)
        return (0);
    matrix->row = rows;
    matrix->col = col;
    matrix->matrix = ret;
    return (1);
}

void    ft_print_matrix(t_matrix *matrix)
{
    size_t  i;

    i = 0;
    while (i < (matrix->row * matrix->col))
    {
        ft_putnbr((int)matrix->matrix[i]);
        if ((i + 1)%(matrix->col) == 0)
            write(1, "\n", 1);
        else
            write(1, "\t", 1);
        i++;
    }
}

void    ft_del_matrix(t_matrix *mat)
{
    if (mat == NULL)
        return ;
    free(mat->matrix);
    free(mat);
    mat = NULL;
}

int ft_get_elem(size_t row, size_t col, t_matrix *matrix)
{
    if ((row + 1) > matrix->row || (col + 1) > matrix->col)
        return (0);
    return ((int)(matrix->matrix[col + (row * matrix->col)]));
}

void    ft_place_val(size_t row, size_t col, double val, t_matrix *matrix)
{
    if (!matrix)
        return ;
    if ((row + 1) > matrix->row || (col + 1) > matrix->col)
        return ;
    matrix->matrix[col + (row * matrix->col)] = val;
}