#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

typedef struct  s_matrix
{
	size_t  row;
	size_t  col;
	double  *matrix;
}   t_matrix;

typedef struct	s_vector
{
	double	*coord;
}	t_vector;

typedef struct	s_map
{
	size_t		row;
	size_t		col;
	t_vector	**data;
	t_matrix	*trans_matrix;
}	t_map;


# include "my_matrix.h"
# include "map_parse.h"



#endif