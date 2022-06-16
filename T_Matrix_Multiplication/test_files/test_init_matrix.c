#include "../includes/my_matrix.h"

#include <stdio.h>

int get_random_num(int lower_lim, int upper_lim)
{
    return ((rand() % (upper_lim - lower_lim + 1)) + lower_lim);
}

void    populate_matrix(t_matrix *matrix)
{
    int i = 0;

    while (i < (matrix->row * matrix->col))
    {
        matrix->matrix[i] = get_random_num(2, 10);
        i++;
    }
}

int main(void)
{
    t_matrix    *matrix;

    matrix = (t_matrix *)malloc(sizeof(t_matrix));
    
    ft_init_matrix(4, 4, matrix);

    printf("Matrix initialized!\nPrinting a blank 4x4 matrix\n");

    ft_print_matrix(matrix);

    printf("\nDone\nPopulating matrix randomly\n");

    populate_matrix(matrix);

    printf("\nDone\nPrinting populated matrix\n");

    ft_print_matrix(matrix);

    printf("\nDone\nExtracting random index\n");

    int row = get_random_num(1, 3);
    int col = get_random_num(1, 3);

    printf("\nmatrix[%d][%d] = %d\n", col, row, ft_get_elem(row, col, matrix));

    printf("\nNow, altering the value of above to 100\n");

    ft_place_val(row, col, 100, matrix);

    printf("\nDone\nPrinting matrix one last time\n");

    ft_print_matrix(matrix);

    printf("\nDone\nDeleting matrix\n");

    ft_del_matrix(matrix);

    if (matrix != NULL)
        printf("Failed to delete\n");
    else
        printf("Success\n");

    return (1);
}