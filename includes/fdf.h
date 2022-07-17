#ifndef FDF_H
# define FDF_H

# define ESC 53
# define UP 126
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define PLUS 24
# define MINUS 27
# define X 7
# define Y 16
# define Z 6

# include <math.h>
# include <fcntl.h>
# include <mlx.h>

# include "../libft/libft.h"

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		update;
}	t_data;

typedef struct	s_img
{
	void	*addr;
	int		bpp;
	int		len;
	int		end;
}	t_img;

typedef struct s_coord
{
	int		set0[2];
	int		set1[2];
}	t_coord;

typedef struct	s_bla
{
	int	dx;
	int	dy;
	int	var_d;
	int	const_i;
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
	double		mid_x;
	double		mid_y;
}	t_map;

/* -.- Driver Function -.- */

/* Main File */


/* Main Helper*/
void		transform_coords(t_map *map, t_matrix *multiplier);

/* Init Data */
t_data		*ft_data_new(void);
t_img		*ft_img_new(t_data *data);
void		ft_img_del(t_img *img, t_data *data);

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
void		fill_coords(t_map *map, int fd, int k);
size_t		ft_row_get(char *file);
size_t		ft_col_get(char *file);

/* Map Utils */
void		ft_free_array(char **str);
void		get_centre(t_map *map, t_matrix **coords);
void		centre_origin(t_map *map, double mid_x, double mid_y);

/* Map Init */
t_map		*ft_map_new(size_t row, size_t col);
void		ft_map_del(t_map *map);

/* -.- Bresenham Functions -.- */

/* Bresenham Utils */
int			ft_abs(double x);
void		plot_pixel(int x, int y, t_img *img);

/* Coord Init */
t_coord		*ft_coords_new(t_matrix *matA, t_matrix *matB);
void		ft_coords_del(t_coord *coord);

/* Algorithm */
void		plot_line(t_matrix *matA, t_matrix *matB, t_img *img);
void		plot_line_low(int setA[2], int setB[2], t_img *img);
void		plot_line_high(int setA[2], int setB[2], t_img *img);

/* -.- GNL Function -.- */

char		*get_next_line(int fd);
ssize_t		read_buff(int fd, char **buff, ssize_t *read_ret);
void		handle_buff(char **stat_str, char **buff);
char		*final_line(char **stat_str);
char		*ft_strldup(char const *s, int len);
void		ft_handleptr(char **ptr, int mode);

#endif