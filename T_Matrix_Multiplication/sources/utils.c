#include "../includes/my_matrix.h"

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