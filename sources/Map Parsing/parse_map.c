/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:02:03 by jthor             #+#    #+#             */
/*   Updated: 2022/07/20 19:02:04 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (temp == NULL || temp[0] == '\n')
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
	temp_split = ft_split_alt(temp_gnl, " \n");
	while (temp_split[ret] != NULL)
		ret++;
	if (ret == 0)
		err_msg("File invalid");
	free(temp_gnl);
	ft_free_array(temp_split);
	close(fd);
	return (ret);
}

void	ft_check_col(char **str, size_t col)
{
	size_t		x;

	if (str == NULL)
		return ;
	x = 0;
	while (str[x] != NULL)
		x++;
	if (x != col)
		err_msg("Format error : Inconsistent column length");
}

void	fill_coords(t_map *map, int fd, t_mod *mod)
{
	int		i;
	char	**temp_split;
	char	*temp_gnl;

	i = -1;
	temp_gnl = get_next_line(fd);
	temp_split = ft_split_alt(temp_gnl, " \n");
	ft_check_col(temp_split, map->col);
	while (++i < (int)(map->row * map->col))
	{
		map->coord[i] = ft_set_coords(i, map, mod, temp_split);
		if ((i + 1) % map->col == 0)
		{
			ft_free_array(temp_split);
			free(temp_gnl);
			temp_gnl = get_next_line(fd);
			temp_split = ft_split_alt(temp_gnl, " \n");
			ft_check_col(temp_split, map->col);
		}
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
	ret->mod = iso_init(col * row);
	fd = open(file, O_RDONLY);
	fill_coords(ret, fd, ret->mod);
	close(fd);
	centre_origin(ret, ret->coord);
	return (ret);
}
