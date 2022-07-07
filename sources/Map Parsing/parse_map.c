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
	free(temp_split);
	close(fd);
	return (ret);
}

void	ft_map_fill_data(t_map *map, int fd)
{
	size_t	i;
	size_t	col;
	double	k;
	char	**temp_split;

	k = 100;
	i = 0;
	col = map->col;
	temp_split = ft_split(get_next_line(fd), ' ');
	while (i < (map->col * map->row))
	{
		if (ft_check_col(temp_split) != map->col)
			err_msg("Map is not formatted properly");
		// fix this
		map->coord[i] = ft_vector_new((i % col) * k, (i / col) * k, 
											ft_atoi(*temp_split), 1);
		temp_split++;
		if (*temp_split == NULL)
		{
			ft_free_array(temp_split);
			temp_split = ft_split(get_next_line(fd), ' ');
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
	ft_map_fill_data(ret, file);
	close(fd);

	return (ret);
}