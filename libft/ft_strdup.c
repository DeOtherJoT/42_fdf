/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 21:39:23 by jthor             #+#    #+#             */
/*   Updated: 2021/09/29 21:39:24 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*retptr;
	int		i;

	retptr = (char *)malloc(ft_strlen(s1) + 1);
	if (retptr == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		retptr[i] = s1[i];
		i++;
	}
	retptr[i] = '\0';
	return (retptr);
}
