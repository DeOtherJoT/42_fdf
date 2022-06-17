#include "../includes/my_matrix.h"

t_matrix    *ft_matrix_new(size_t rows, size_t col)
{
    t_matrix    *ret;

    if (rows <= 0 || col <= 0)
        return (0);
    ret = malloc(sizeof(t_matrix));
    if (ret == NULL)
        return (NULL);
    ret->row = rows;
    ret->col = col;
    ret->matrix = ft_calloc(rows * col, sizeof(double));
    if (ret->matrix == NULL)
        return (NULL);
    return (ret);
}

void    ft_matrix_del(t_matrix *mat)
{
    if (mat == NULL)
        return ;
    free(mat->matrix);
    free(mat);
}

double  ft_matrix_get(t_matrix *matrix, size_t row, size_t col)
{
    if (row >= matrix->row || col >= matrix->col)
        err_msg("Error at ft_matrix_get()");
    return ((matrix->matrix[col + (row * matrix->col)]));
}

void    ft_matrix_set(t_matrix *matrix, size_t row, size_t col, double val)
{
    if (!matrix)
        return ;
    if (row >= matrix->row || col >= matrix->col)
        err_msg("Error at ft_matrix_set()");
    matrix->matrix[col + (row * matrix->col)] = val;
}