#ifndef MAP_PARSE_H
# define MAP_PARSE_H

t_map	*parse_map(char *file);

size_t	ft_row_get(char *file);
size_t	ft_col_get(char *file);

/* Map Functions */
t_map		*ft_map_new(size_t row, size_t col);
void		ft_map_del(t_map *map);

#endif