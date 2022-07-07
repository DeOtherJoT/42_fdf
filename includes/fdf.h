#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>

typedef struct  s_matrix
{
	size_t  row;
	size_t  col;
	double  *matrix;
}   t_matrix;

typedef struct	s_map
{
	size_t		row;
	size_t		col;
	t_matrix	**coord;
	t_matrix	*trans_matrix;
}	t_map;


# include "my_matrix.h"
# include "map_parse.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"



#endif