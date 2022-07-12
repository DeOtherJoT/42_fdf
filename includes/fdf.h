#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <fcntl.h>
# include <mlx.h>

# include "libft.h"
# include "get_next_line.h"

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		update;
}	t_data;

typedef struct	s_img
{
	void	*img_addr;
	int		bpp;
	int		len;
	int		endian;
}	t_img;

typedef struct	s_bla
{
	int		sx;
	int		sy;
	int		err;
	int		dx;
	int		dy;
}	t_bla;

typedef struct	s_matrix
{
	size_t	row;
	size_t	col;
	double	*matrix;
}	t_matrix;

typedef struct	s_map
{
	size_t		row;
	size_t		col;
	t_matrix	**coord;
	t_matrix	*trans_matrix;
}	t_map;

/* -.- Matrix Functions -.- */

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
void		ft_matrix_translate(t_matrix *trans, double x, double y, double z);
void		ft_matrix_scale(t_matrix *trans, double x, double y, double z);
void		ft_matrix_shear(t_matrix *trans, double x, double y, double z);

/* Affine Rotation */
double		ft_deg_to_rad(double deg);
void		ft_matrix_rotate_x(t_matrix *trans, double x);
void		ft_matrix_rotate_y(t_matrix *trans, double y);
void		ft_matrix_rotate_z(t_matrix *trans, double z);

/* -.- Map Functions -.- */

/* Map Parsing */
t_map		*parse_map(char *file);
void		ft_check_col(char **str, size_t col);
void		fill_coords(t_map *map, int fd);
size_t		ft_row_get(char *file);
size_t		ft_col_get(char *file);

/* Map Utils */
void		ft_free_array(char **str);

/* Map Init */
t_map		*ft_map_new(size_t row, size_t col);
void		ft_map_del(t_map *map);

#endif