#ifndef MY_MATRIX_H
# define MY_MATRIX_H

/* Basic Utils */
void		*ft_calloc(size_t n_elem, size_t t_size);
void		*ft_memcpy(void *dst, const void *src, size_t len);
size_t		ft_strlen(char *str);
void		err_msg(char *str);

/* Basic Matrix Functions */
t_matrix	*ft_matrix_new(size_t rows, size_t col);
void		ft_matrix_del(t_matrix *matrix);
double		ft_matrix_get(t_matrix *matrix, size_t row, size_t col);
void		ft_matrix_set(t_matrix *matrix, size_t row, size_t col, double val);
t_matrix	*ft_matrix_create(size_t row, size_t col, double *data);

/* Matrix Multiplication */
t_matrix	*ft_matrix_mult(t_matrix *matA, t_matrix *matB);
t_matrix	*ft_matrix_ident(size_t size);
void		ft_matrix_swap(t_matrix *matA, t_matrix *matB);
void		ft_matrix_mult_swp(t_matrix *result, t_matrix *multiplier);

/* Affine Transformation */
void	ft_matrix_translate(t_matrix *trans, double x, double y, double z);
void	ft_matrix_scale(t_matrix *trans, double x, double y, double z);
void	ft_matrix_shear(t_matrix *trans, double x, double y, double z);

/* Affine Rotation */
double	ft_deg_to_rad(double deg);
void	ft_matrix_rotate_x(t_matrix *trans, double x);
void	ft_matrix_rotate_y(t_matrix *trans, double y);
void	ft_matrix_rotate_z(t_matrix *trans, double z);

#endif