/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 21:39:32 by jthor             #+#    #+#             */
/*   Updated: 2021/09/29 21:39:34 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*retptr;
	char	*save;

	retptr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!retptr)
		return (NULL);
	save = retptr;
	while (*s1)
		*save++ = *s1++;
	while (*s2)
		*save++ = *s2++;
	*save = '\0';
	return (retptr);
}
