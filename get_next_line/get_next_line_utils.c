/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:57:40 by jthor             #+#    #+#             */
/*   Updated: 2022/01/13 20:59:39 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                           *
 * Standard function to get the length of the string str.                    *
 *                                                                           *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                           *
 * Standard function to check for the existence of the character c in the    *
 * string s.                                                                 *
 *                                                                           *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

char	*ft_strchr(char const *s, int c)
{
	if (c >= 256)
		c -= 256;
	while (*s && *s != c)
		s++;
	if (*s == c)
		return ((char *)s);
	return (0);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                           *
 * Standard function to allocate memory and concatenate s2 to s1.            *
 *                                                                           *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

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

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                           *
 * A slightly modified version of ft_strdup, where the parameter len is      *
 * added to limit the length of the string s1 that is duplicated.            *
 *                                                                           *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

char	*ft_strldup(char const *s1, int len)
{
	char	*retptr;
	int		i;

	if (len <= 0)
		return (NULL);
	retptr = (char *)malloc((len + 1) * sizeof(char));
	if (!retptr)
		return (NULL);
	i = 0;
	while (s1[i] && i < len)
	{
		retptr[i] = s1[i];
		i++;
	}
	retptr[i] = '\0';
	return (retptr);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                           *
 * Helper function that handles pointers. There are two modes, represented   *
 * by 0 and 1.                                                               *
 *                                                                           *
 * 0 :- Initialises the pointer to be used as a string.                      *
 * 1 :- Frees the content of the pointer and assigns it to NULL, as a        *
 *      standard practice.                                                   *
 *                                                                           *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void	ft_handleptr(char **ptr, int mode)
{
	if (mode == 0)
	{
		*ptr = (char *)malloc(1 * sizeof(char));
		(*ptr)[0] = '\0';
	}
	else if (mode == 1)
	{
		free(*ptr);
		*ptr = NULL;
	}
}
