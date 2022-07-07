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
