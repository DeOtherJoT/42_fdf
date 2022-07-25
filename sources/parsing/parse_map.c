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

/*
Opens the file and gets the number of columns from the first row.
After that, use get_next_line repetitively to get the number of rows.
Row and col are passed by reference so they can be modified.
*/
void	ft_row_col_get(size_t *row, size_t *col, char *file)
{
	int		fd;
	char	*temp_gnl;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		err_msg("File cannot be opened");
	temp_gnl = get_next_line(fd);
	*col = ft_col_get(temp_gnl);
	*row = 1;
	while (1 == 1)
	{
		free(temp_gnl);
		temp_gnl = get_next_line(fd);
		if (temp_gnl == NULL || temp_gnl[0] == '\n')
			break ;
		*row += 1;
	}
	free(temp_gnl);
	close(fd);
}

/*
Splits the line and counts and returns the number of columns of the first row.
This is then used as the baseline for the other rows.
*/

size_t	ft_col_get(char *line)
{
	size_t	ret;
	char	**temp_split;

	ret = 0;
	temp_split = ft_split_alt(line, " \n");
	while (temp_split[ret] != NULL)
		ret++;
	ft_free_array(temp_split);
	return (ret);
}

/*
For every row, check the number of columns with the first row.
Exits the program if the number of colums are inconsistent.
*/

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

/*
Gets each row from the .fdf file, seperates the columns and assigns
each coordinate
*/

void	fill_coords(t_map *map, int fd)
{
	size_t	i;
	char	**temp_split;
	char	*temp_gnl;

	i = -1;
	temp_gnl = get_next_line(fd);
	temp_split = ft_split_alt(temp_gnl, " \n");
	ft_check_col(temp_split, map->col);
	while (++i < (map->row * map->col))
	{
		map->coord[i] = ft_set_coords(i, map, temp_split);
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

/*
Gets the size of the map from the fdf file and creates a new t_map instance.
The individual altitudes are given a (x, y, z, w) coordinate location in
fill_coords().
*/

t_map	*parse_map(char *file)
{
	size_t	row;
	size_t	col;
	t_map	*ret;
	int		fd;

	ft_row_col_get(&row, &col, file);
	if (row <= 1 || col <= 1)
		err_msg("Format error : Row or col cannot be 1 or lesser");
	ret = ft_map_new(row, col);
	fd = open(file, O_RDONLY);
	fill_coords(ret, fd);
	close(fd);
	return (ret);
}
