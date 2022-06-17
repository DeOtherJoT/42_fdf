#include "../includes/my_matrix.h"

#include <stdio.h>
#include <time.h>

void    print_matrix(t_matrix *matrix)
{
    size_t  i;

    i = 0;
    while (i < (matrix->row * matrix->col))
    {
        printf("%d", matrix->matrix[i]);
        if ((i + 1)%(matrix->col) == 0)
            write(1, "\n", 1);
        else
            write(1, "\t", 1);
        i++;
    }
}

int get_random_num(int lower_lim, int upper_lim)
{
    return ((rand() % (upper_lim - lower_lim + 1)) + lower_lim);
}

void    populate_matrix(t_matrix *matrix)
{
    int i = 0;

    while (i < (matrix->row * matrix->col))
    {
        matrix->matrix[i] = get_random_num(0, 10);
        i++;
    }
}

int main(void)
{
    t_matrix    *matrix;
    
    matrix = ft_matrix_new(4, 4);

    printf("Matrix initialized!\nPrinting a blank 4x4 matrix\n");

    print_matrix(matrix);

    printf("\nDone\nPopulating matrix randomly\n");

    srand(time(0));

    populate_matrix(matrix);

    printf("\nDone\nPrinting populated matrix\n");

    print_matrix(matrix);

    printf("\nDone\nExtracting random index\n");

    int row = get_random_num(0, 3);
    int col = get_random_num(0, 3);

    printf("\nmatrix[%d][%d] = %d\n", col, row, ft_get_elem(row, col, matrix));

    printf("\nNow, altering the value of above to 100\n");

    ft_place_val(row, col, 100, matrix);

    printf("\nDone\nPrinting matrix one last time\n");

    print_matrix(matrix);

    printf("\nDone\nDeleting matrix\n");

    ft_del_matrix(matrix);

    if (matrix != NULL)
        printf("Failed to delete\n");
    else
        printf("Success\n");

    return (1);
}