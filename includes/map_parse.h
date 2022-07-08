#ifndef MAP_PARSE_H
# define MAP_PARSE_H

typedef struct	s_map
{
	size_t		row;
	size_t		col;
	t_matrix	**coord;
	t_matrix	*trans_matrix;
}	t_map;

t_map		*parse_map(char *file);
void		ft_check_col(const char **str, size_t col);
void		fill_coords(t_map *map, int fd);
size_t		ft_row_get(char *file);
size_t		ft_col_get(char *file);


/* Map Utils */
void		ft_free_array(char **str);

/* Map Functions */
t_map		*ft_map_new(size_t row, size_t col);
void		ft_map_del(t_map *map);

#endif