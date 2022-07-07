/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 21:39:41 by jthor             #+#    #+#             */
/*   Updated: 2021/09/29 21:39:42 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char	*dst, const char *src, size_t dstsize)
{
	size_t	dst_index;

	if (dstsize == 0)
		return (ft_strlen(src));
	else if (dstsize < ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	else
	{	
		dst_index = 0;
		while (dst[dst_index])
			dst_index++;
		while (*src && (dst_index < dstsize - 1))
		{
			dst[dst_index] = *src;
			src++;
			dst_index++;
		}
		dst[dst_index] = '\0';
		return (ft_strlen(dst) + ft_strlen(src));
	}
}
