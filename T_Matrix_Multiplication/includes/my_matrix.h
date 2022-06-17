#ifndef MY_MATRIX_H
# define MY_MATRIX_H
# include <unistd.h>
# include <stdlib.h>

typedef struct  s_matrix
{
    size_t  row;
    size_t  col;
    double  *matrix;
}   t_matrix;

/* Basic Utils */
void    *ft_calloc(size_t n_elem, size_t t_size);
size_t  ft_strlen(char *str);
void    err_msg(char *str);

/* Matrix Functions */
t_matrix    *ft_matrix_new(size_t rows, size_t col);
void        ft_matrix_del(t_matrix *matrix);
double      ft_matrix_get(t_matrix *matrix, size_t row, size_t col);
void        ft_matrix_set(t_matrix *matrix, size_t row, size_t col, double val);
#endif