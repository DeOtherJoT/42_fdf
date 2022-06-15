#include "matrix_mult.h"

int ft_init_matrix(t_matrix *result, t_matrixA *matrixA, t_matrixB *matrixB)
{
    int i;

    if (matrixA->col != matrixB->row)
        return (0);
    result->row = matrixA->row;
    result->col = matrixB->col;
    result->matrix = (int **)malloc(sizeof(int *) * (result->row));
    i = 0;
    while (i < result->col)
    {
        result->matrix[i] = (int *)malloc(sizeof(int) * (result->col));
        i++;
    }
    return (1);
}

int ft_mult_matrix(t_matrix *result, t_matrixA *matrixA, t_matrixB *matrixB)
{
    int i;
    int j;
    int k;

    if (!ft_init_matrix(result, matrixA, matrixB))
        return (0);
    i = 0;
    while (i < matrixA->row)
    {
        j = 0;
        while (j < matrixB->col)
        {
            result->matrix[i][j] = 0;
            k = 0;
            while (k < matrixA->col)
            {
                result->matrix[i][j] += matrixA->matrix[i][k] * matrixB->matrix[k][j];
                k++;
            }
            j++;
        }
        i++;
    }
    return (1);
}

#include <stdio.h>

int main(void)
{
    t_matrix    *result;
    t_matrixA    *matrixA;
    t_matrixB    *matrixB;
    int matrix_a[4][4] = {{1,2,3,4}, {1,2,3,4}, {1,2,3,4}, {1,2,3,4}};
    int matrix_b[4][1] = {{1},{2},{3},{4}};

    result = (t_matrix *)malloc(sizeof(t_matrix));
    matrixA = (t_matrixA *)malloc(sizeof(t_matrixA));
    matrixB = (t_matrixB *)malloc(sizeof(t_matrixB));

    matrixA->matrix = matrix_a;
    matrixA->row = 4;
    matrixA->col = 4;

    matrixB->matrix =  matrix_b;
    matrixB->row = 4;
    matrixB->col = 1;

    ft_mult_matrix(result, matrixA, matrixB);

    int i;
    int j;

    i = 0;
    while (i < result->row)
    {
        j = 0;
        while (j < result->col)
        {
            printf("%d ", result->matrix[i][j]);
            j++;
        }
        i++;
    }

    return (1);
}