#include "../includes/fdf.h"

/* ------- Actual test functions ------- */

void	test_row_get(void)
{
	char	file[] = "../test_maps/basictest.fdf";
	size_t	res = ft_row_get(file);

	if (res == 9)
		printf("ft_row_get :\tSuccess!\n");
	else
		printf("ft_row_get : KO\n");
}

void	test_col_get(void)
{
	char	file[] = "../test_maps/basictest.fdf";
	size_t	res = ft_col_get(file);

	if (res == 9)
		printf("ft_col_get :\tSuccess!\n");
	else
		printf("ft_col_get : KO\n");
}

void	test_parse_map(void)
{
	char	file[] = "../test_maps/basictest.fdf";
	t_map	*map;

	map = parse_map(file);
}

int	main(void)
{
	test_row_get();
	test_col_get();
	test_map_new();
	test_parse_map();
}