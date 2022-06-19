#include "../includes/my_matrix.h"

#include <stdio.h>
#include <time.h>

/* ------- Tester utils ------- */

int cmp_matrix(t_matrix *matA, t_matrix *matB)
{
    size_t  i;

    if (matA->row != matB->row || matA->col != matB->col)
        return (1);
    i = 0;
    while (i < (matA->row * matA->col))
    {
        if (matA->matrix[i] != matB->matrix[i])
            return (1);
        i++;
    }
    return (0);
}

void    print_matrix(t_matrix *matrix)
{
    size_t  i;

    i = 0;

    printf("Row = %lld\n", matrix->row);
    printf("Col = %lld\n", matrix->col);
    while (i < (matrix->row * matrix->col))
    {
        printf("%f", matrix->matrix[i]);
        if ((i + 1)%(matrix->col) == 0)
            write(1, "\n", 1);
        else
            write(1, "\t", 1);
        i++;
    }
}

float   get_random_num(int lower_lim, int upper_lim)
{
    return ((rand() % (upper_lim - lower_lim + 1)) + lower_lim);
}

void    populate_matrix(t_matrix *matrix)
{
    size_t i = 0;

    while (i < (matrix->row * matrix->col))
    {
        matrix->matrix[i] = get_random_num(0, 10);
        i++;
    }
}

/* ------- Actual test functions ------- */

void    test_matrix_new(void)
{
    t_matrix    *matrix;
    size_t      test_row = 4;
    size_t      test_col = 4;
    size_t      i = 0;

    matrix = ft_matrix_new(test_row, test_col);

    if (matrix->row != test_row || matrix->col != test_col)
    {
        printf("ft_matrix_new : KO!\n");
        return ;
    }
    while (i < (test_row * test_col))
    {
        if (matrix->matrix[i] != 0)
        {
            printf("ft_matrix_new : KO!\n");
            return ;
        }
        i++;
    }
    printf("ft_matrix_new : Success!\n");
    ft_matrix_del(matrix);
}

void    test_matrix_get(void)
{
    t_matrix    *matrix;
    size_t      i = 0;
    size_t      j;

    matrix = ft_matrix_new(3, 3);
    while (i < matrix->row)
    {
        j = 0;
        while (j < matrix->col)
        {
            if (ft_matrix_get(matrix, i, j) != 0)
            {
                printf("ft_matrix_get : KO!\n");
                return ;
            }
            j++;
        }
        i++;
    }
    printf("ft_matrix_get : Success!\n");
    ft_matrix_del(matrix);
}

void    test_matrix_set(void)
{
    t_matrix    *matrix;
    float       val = 100;

    matrix = ft_matrix_new(5, 5);
    ft_matrix_set(matrix, 2, 2, val);
    if (ft_matrix_get(matrix, 2, 2) != val)
    {
        printf("ft_matrix_set : KO!\n");
        return ;
    }
    printf("ft_matrix_set : Success!\n");
    ft_matrix_del(matrix);
}

int main(void)
{
    test_matrix_new();
    test_matrix_get();
    test_matrix_set();
}
