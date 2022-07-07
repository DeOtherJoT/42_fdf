/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 21:35:44 by jthor             #+#    #+#             */
/*   Updated: 2021/09/29 21:35:47 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*retptr;
	size_t	i;

	retptr = (void *)malloc(count * size);
	if (!retptr)
		return (NULL);
	i = 0;
	while (i < (count * size))
	{
		((char *)retptr)[i] = 0;
		i++;
	}
	return (retptr);
}
