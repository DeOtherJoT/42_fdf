/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:02:31 by jthor             #+#    #+#             */
/*   Updated: 2021/10/13 20:30:25 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	copy_len(char const *s, unsigned int start, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*retptr;

	if (start + 1 > ft_strlen(s))
	{
		retptr = ft_strdup("");
		return (retptr);
	}
	retptr = (char *)malloc(copy_len(s, start, len) + 1);
	if (!retptr)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		retptr[i] = s[start + i];
		i++;
	}
	retptr[i] = '\0';
	return (retptr);
}

static size_t	copy_len(char const *s, unsigned int start, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && s[start + i])
		i++;
	return (i);
}
