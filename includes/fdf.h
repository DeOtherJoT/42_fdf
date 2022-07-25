/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:15:19 by jthor             #+#    #+#             */
/*   Updated: 2022/07/20 19:15:21 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define SCR_WIDTH 1920
# define SCR_HEIGHT 1080
# define ESC 53
# define UP 126
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define PLUS 24
# define MINUS 27
# define K_I 34
# define K_O 31
# define K_P 35
# define K_J 38
# define K_K 40
# define K_L 37
# define K_B 11
# define K_N 45
# define K_M 46
# define K_Z 6
# define K_X 7
# define K_C 8
# define K_DEL 51

# include <math.h>
# include <fcntl.h>
# include <mlx.h>

# include "../libft/libft.h"

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
}	t_data;

typedef struct s_img
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

typedef struct s_bla
{
	int	dx;
	int	dy;
	int	var_d;
	int	const_i;
}	t_bla;

typedef struct s_matrix
{
	size_t	row;
	size_t	col;
	double	*matrix;
}	t_matrix;

typedef struct s_map
{
	size_t		row;
	size_t		col;
	t_data		*data;
	t_img		*img;
	t_matrix	**coord;
	t_matrix	*trans_rot;
	t_matrix	*trans_late;
	t_matrix	*trans_scale;
}	t_map;

/* -.- Driver Function -.- */

// Main File
int			close_prog(void);
int			ft_handle_key(int keycode, t_map *map_data);
void		render_first_img(t_data *data, t_img *img, t_map *map);

// Main Helper 2
// t_matrix	*ft_get_trans(t_map *map, int row, int col);
// void		plot_map(t_map *map, t_img *img);

// Main Helper
void		transform_coord(t_matrix **coords, t_map *map, size_t n);
t_matrix	*ft_coord_get(t_map *map, t_matrix **dup, int row, int col);
void		plot_rows(t_map *map, t_matrix **dup, t_img *img);
void		plot_cols(t_map *map, t_matrix **dup, t_img *img);
void		plot_map(t_map *map, t_img *img);

// Main Utils
t_matrix	**ft_duplicate_coords(t_matrix **coords, size_t row, size_t col);
void		ft_del_dup(t_matrix **dup, size_t n);
size_t		ft_decide_scale(size_t size);
size_t		ft_decide_peak(size_t size);

// Init Data
t_data		*ft_data_new(void);
t_img		*ft_img_new(t_data *data);
void		ft_img_del(t_img *img, t_data *data);

/* -.- Bonus Functions -.- */

// Bonus
void		bonus_translate(t_map *map, int key);
void		bonus_peak(t_map *map, int key);
void		bonus_scale(t_map *map, int key);
void		bonus_rotate(t_map *map, int key);
void		bonus_reset(t_map *map);

// Bonus Helper
void		ft_img_refresh(t_map *map);
void		ft_trans_init(t_map *map);
void		render_bonus_img(t_data *data, t_img *img, t_map *map);

/* -.- Matrix Functions -.- */

// Basic Matrix Functions
t_matrix	*ft_matrix_new(size_t rows, size_t col);
void		ft_matrix_del(t_matrix *matrix);
double		ft_matrix_get(t_matrix *matrix, size_t row, size_t col);
void		ft_matrix_set(t_matrix *matrix, size_t row, size_t col, double val);
t_matrix	*ft_matrix_create(size_t row, size_t col, double *data);

// Matrix Multiplication
t_matrix	*ft_matrix_mult(t_matrix *matA, t_matrix *matB);
t_matrix	*ft_matrix_ident(size_t size);
void		ft_matrix_swap(t_matrix *matA, t_matrix *matB);
void		ft_matrix_mult_swp(t_matrix *result, t_matrix *multiplier);
void		ft_matrix_mult_swp2(t_matrix *result, t_matrix *multiplier);

// Matrix Utils
t_matrix	*ft_matrix_cp(t_matrix *mat);

// Affine Transformation
void		ft_matrix_translate(t_matrix *trans, double x, double y, double z);
void		ft_matrix_scale(t_matrix *trans, double x, double y, double z);
void		ft_matrix_shear(t_matrix *trans, double x, double y, double z);
t_matrix	*get_total_trans(t_matrix *scale, t_matrix *rot, t_matrix *late);

// Affine Rotation
double		ft_deg_to_rad(double deg);
void		ft_matrix_rotate_x(t_matrix *trans, double x);
void		ft_matrix_rotate_y(t_matrix *trans, double y);
void		ft_matrix_rotate_z(t_matrix *trans, double z);

/* -.- Map Functions -.- */

// Map Parsing
t_map		*parse_map(char *file);
void		ft_check_col(char **str, size_t col);
void		fill_coords(t_map *map, int fd);
size_t		ft_col_get(char *line);
void		ft_row_col_get(size_t *row, size_t *col, char *file);

// Parse Utils
void		ft_free_array(char **str);
void		centre_origin(t_map *map, t_matrix **coords);
t_matrix	*ft_set_coords(int i, t_map *map, char **split);

// Map Init
t_map		*ft_map_new(size_t row, size_t col);
void		ft_map_del(t_map *map);

/* -.- Bresenham Functions -.- */

// Bresenham Utils
int			ft_abs(double x);
void		plot_pixel(int x, int y, t_img *img);

// Coord Init
t_coord		*ft_coords_new(t_matrix *matA, t_matrix *matB);
void		ft_coords_del(t_coord *coord);

// Algorithm
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
