#include "libft.h"

void	err_msg(const char *str)
{
	write(2, "Error message: ", 15);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	perror("Error Description: ");
	exit(EXIT_FAILURE);
}