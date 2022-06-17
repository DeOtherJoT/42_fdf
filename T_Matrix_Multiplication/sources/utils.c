#include "../includes/my_matrix.h"

size_t  ft_strlen(char  *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

void    *ft_calloc(size_t n_elem, size_t t_size)
{
    void    *ret;
    size_t  i;

    ret = malloc(n_elem * t_size);
    if (!ret)
        return (ret);
    i = 0;
    while (i < (n_elem * t_size))
    {
        ((char *)ret)[i] = 0;
        i++;
    }
    return (ret);
}

void    err_msg(char *str)
{
    write(2, "Error message: ", 15);
    write(2, str, ft_strlen(str));
    write(2, "\n", 1);
    perror("Error description: ");
    exit(EXIT_FAILURE);
}