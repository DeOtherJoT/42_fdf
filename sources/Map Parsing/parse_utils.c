#include "../../includes/fdf.h"

void	ft_free_array(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	get_centre(t_map *map)
{
	map->mid_x = ft_matrix_get(map);
}