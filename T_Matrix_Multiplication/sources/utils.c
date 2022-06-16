#include "../includes/my_matrix.h"

void    ft_putchar(char c)
{
    write(1, &c, 1);
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

void    ft_putnbr(int n)
{
    if (n == -2147483648)
    {
        ft_putnbr(n / 10);
        ft_putchar('8');
    }
    else
    {
        if (n < 0)
        {
            n *= -1;
            ft_putchar('-');
        }
        if (n < 10)
            ft_putchar('0' + n);
        else
        {
            ft_putnbr(n / 10);
            ft_putnbr(n % 10);
        }
    }
}