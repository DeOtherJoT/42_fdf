/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 21:37:17 by jthor             #+#    #+#             */
/*   Updated: 2021/09/29 21:42:38 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calc_total_len(int n);

static void	fill_array(int n, int numb_len, char *retptr);

char	*ft_itoa(int n)
{
	int		numb_len;
	char	*retptr;

	numb_len = calc_total_len(n);
	retptr = (char *)malloc((numb_len + 1) * sizeof(char));
	if (!retptr)
		return (NULL);
	fill_array(n, numb_len, retptr);
	return (retptr);
}

static int	calc_total_len(int n)
{
	int	retval;

	if (n <= 0)
		retval = 1;
	else
		retval = 0;
	while (n)
	{
		n /= 10;
		retval++;
	}
	return (retval);
}

static void	fill_array(int n, int numb_len, char *retptr)
{
	int				loop_ctrl;
	int				index_ctrl;
	unsigned int	nb;

	if (n < 0)
	{
		retptr[0] = '-';
		loop_ctrl = 1;
		index_ctrl = 0;
		nb = n * -1;
	}
	else
	{
		loop_ctrl = 0;
		index_ctrl = 1;
		nb = n;
	}
	while (loop_ctrl < numb_len)
	{
		retptr[numb_len - index_ctrl - loop_ctrl] = "0123456789"[nb % 10];
		nb /= 10;
		loop_ctrl++;
	}
	retptr[numb_len] = '\0';
}
