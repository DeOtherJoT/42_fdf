#include "../includes/my_matrix.h"

t_matrix    *ft_matrix_ident(size_t size)
{
    t_matrix    *ret;
    size_t      i;

    if (size == 0)
        err_msg("Error at ft_matrix_ident() : size cannot be 0");
    ret = ft_matrix_new(size, size);
    i = 0;
    while (i < size)
    {
        ft_matrix_set(ret, i, i, 1);
        i++;
    }
    return (ret);
}

void    ft_matrix_swap(t_matrix *matA, t_matrix *matB)
{
    double  *temp_data;
    size_t  temp_row;
    size_t  temp_col;

    temp_row = matA->row;
    temp_col = matA->col;
    temp_data = matA->matrix;

    matA->row = matB->row;
    matA->col = matB->col;
    matA->matrix = matB->matrix;

    matB->row = temp_row;
    matB->col = temp_col;
    matB->matrix = temp_data;
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

void    ft_matrix_mult_swp(t_matrix *result, t_matrix *multiplier)
{
    t_matrix    *temp;

    temp = ft_matrix_mult(result, multiplier);
    ft_matrix_swap(temp, result);
    ft_matrix_del(temp);
}