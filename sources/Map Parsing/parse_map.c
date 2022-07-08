#include "../../includes/fdf.h"

size_t	ft_row_get(char *file)
{
	int		fd;
	char	*temp;
	size_t	ret;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		err_msg("File cannot be opened");
	ret = 0;
	while (1 == 1)
	{
		temp = get_next_line(fd);
		if (temp == NULL)
			break ;
		ret++;
		free(temp);
	}
	if (ret == 0)
		err_msg("File invalid");
	close(fd);
	return (ret);
}

size_t	ft_col_get(char *file)
{
	int		fd;
	char	*temp_gnl;
	char	**temp_split;
	size_t	ret;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		err_msg("File cannot be opened");
	ret = 0;
	temp_gnl = get_next_line(fd);
	temp_split = ft_split(temp_gnl, ' ');
	while (temp_split[ret] != NULL)
	{
		free(temp_split[ret]);
		ret++;
	}
	if (ret == 0)
		err_msg("File invalid");
	free(temp_gnl);
	ft_free_array(temp_split);
	close(fd);
	return (ret);
}

void	ft_check_col(const char **str, size_t col)
{
	static int	i;
	size_t		x;

	i = 0;
	if (str == NULL)
	{
		if (i = 0)
			err_msg(".fdf file is not formatted properly");
		else
			return ;
	}
	i++;
	x = 0;
	while (str[i] != NULL)
		x++;
	if (x != col)
		err_msg(".fdf file is not formatted properly");
}

void	fill_coords(t_map *map, int fd)
{
	size_t	i;
	double	k;
	char	**temp_split;

	k = 10;
	i = 0;
	temp_split = ft_split(get_next_line(fd), ' ');
	ft_check_col(temp_split, map->col);
	while (i < (map->col * map->row))
	{
		map->coord[i] = ft_matrix_new(4, 1);
		ft_matrix_set(map->coord[i], 0, 0, (i % map->col) * k);
		ft_matrix_set(map->coord[i], 1, 0, (i / map->col) * k);
		ft_matrix_set(map->coord[i], 2, 0, ft_atoi(temp_split[i % map->col]));
		ft_matrix_set(map->coord[i], 3, 0, 1);
		if ((i + 1) % map->col == 0)
		{
			ft_free_array(temp_split);
			temp_split = ft_split(get_next_line(fd), ' ');
			ft_check_col(temp_split, map->col);
		}
		i++;
	}
}

t_map	*parse_map(char *file)
{
	size_t	row;
	size_t	col;
	t_map	*ret;
	int		fd;

	row = ft_row_get(file);
	col = ft_col_get(file);
	ret = ft_map_new(row, col);
	fd = open(file, O_RDONLY);
	fill_coords(ret, file);
	close(fd);
	return (ret);
}