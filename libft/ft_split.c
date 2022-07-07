/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 21:38:26 by jthor             #+#    #+#             */
/*   Updated: 2021/10/13 14:01:12 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char c);

static int	word_len(char const *s, char c);

static int	word_split(char const *s, char c, char **ret, int i);

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		words;
	int		i;
	int		temp;

	if (!s)
		return (NULL);
	words = word_count(s, c);
	ret = (char **)malloc((words + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*s == c)
			s++;
		temp = word_split(s, c, ret, i);
		if (!temp)
			return (NULL);
		while (*s && *s != c)
			s++;
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

static int	word_count(char const *s, char c)
{
	int	ret;

	ret = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			ret++;
			while (*s && *s != c)
				s++;
		}
	}
	return (ret);
}

static int	word_len(char const *s, char c)
{
	int	ret;

	ret = 0;
	while (*s && *s != c)
	{
		ret++;
		s++;
	}
	return (ret);
}

static int	word_split(char const *s, char c, char **ret, int i)
{
	int	j;

	ret[i] = (char *)malloc((word_len(s, c) + 1) * sizeof(char));
	if (!ret[i])
	{
		free(ret);
		return (0);
	}
	j = 0;
	while (*s && *s != c)
		ret[i][j++] = *s++;
	ret[i][j] = '\0';
	return (1);
}
