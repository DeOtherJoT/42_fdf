/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 21:41:19 by jthor             #+#    #+#             */
/*   Updated: 2021/09/29 21:41:21 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*retptr;
	size_t	len;

	while (*s1 && is_in_set(*s1, set))
		s1++;
	if (!(s1[0]))
	{
		retptr = (char *)malloc(sizeof(char));
		*retptr = '\0';
		return (retptr);
	}
	len = ft_strlen(s1);
	while (is_in_set(s1[len - 1], set))
		len--;
	retptr = ft_substr(s1, 0, len);
	return (retptr);
}

static int	is_in_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}
