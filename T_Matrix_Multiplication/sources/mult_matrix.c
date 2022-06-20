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