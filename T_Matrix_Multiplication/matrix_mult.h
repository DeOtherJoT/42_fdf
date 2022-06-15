#include <unistd.h>
#include <stdlib.h>

typedef struct  s_matrixB
{
    int row;
    int col;
    int matrix[4][1];
}   t_matrixB;

typedef struct s_matrixA
{
    int row;
    int col;
    int matrix[4][4];
}   t_matrixA;


typedef struct  s_matrix
{
    int row;
    int col;
    int **matrix;
}   t_matrix;