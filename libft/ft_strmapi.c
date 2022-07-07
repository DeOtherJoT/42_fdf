/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 21:40:18 by jthor             #+#    #+#             */
/*   Updated: 2021/09/29 21:40:20 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*retptr;
	unsigned int	i;

	retptr = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!retptr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		retptr[i] = f(i, s[i]);
		i++;
	}
	retptr[i] = '\0';
	return (retptr);
}
