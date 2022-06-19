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
void    *ft_memcpy(void *dst, const void *src, size_t len);
size_t  ft_strlen(char *str);
void    err_msg(char *str);

/* Basic Matrix Functions */
t_matrix    *ft_matrix_new(size_t rows, size_t col);
void        ft_matrix_del(t_matrix *matrix);
double      ft_matrix_get(t_matrix *matrix, size_t row, size_t col);
void        ft_matrix_set(t_matrix *matrix, size_t row, size_t col, double val);
t_matrix    *ft_matrix_create(size_t row, size_t col, double *data);

/* Matrix Multiplication */
t_matrix    *ft_matrix_mult(t_matrix *matA, t_matrix *matB);
#endif