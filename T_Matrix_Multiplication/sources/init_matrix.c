#include "../includes/my_matrix.h"

t_matrix    *ft_matrix_new(size_t rows, size_t col)
{
    t_matrix    *ret;

    if (rows == 0 || col == 0)
        err_msg("New matrix cannot have 0 rows/col");
    ret = malloc(sizeof(t_matrix));
    if (ret == NULL)
        err_msg("Error on malloc ret matrix");
    ret->row = rows;
    ret->col = col;
    ret->matrix = ft_calloc(rows * col, sizeof(double));
    if (ret->matrix == NULL)
        err_msg("Error on ft_calloc ret matrix data");
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

t_matrix    *ft_matrix_mult(t_matrix *matA, t_matrix *matB)
{
    t_matrix    *ret;
    size_t      i;
    size_t      j;
    float       temp_val;

    if (matA->col != matB->row)
        err_msg("Two matrices cannot be multiplied");
    ret = ft_matrix_new(matA->row, matB->col);
    i = 0;
    while (i < (ret->row *ret->col))
    {
        temp_val = 0;
        j = 0;
        while (j < matA->col)
        {
            temp_val += ft_matrix_get(matA, i / ret->col, j) 
                        * ft_matrix_get(matB, j, i % ret->col);
            j++;
        }
        ft_matrix_set(ret, i / ret->col, i % ret->col, temp_val);
        i++;
    }
    return (ret);
}