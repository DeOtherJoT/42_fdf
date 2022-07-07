/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:30:24 by jthor             #+#    #+#             */
/*   Updated: 2021/10/12 21:44:04 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next_in_list;

	if (*lst)
	{
		current = *lst;
		while (current)
		{
			next_in_list = current->next;
			del(current->content);
			free(current);
			current = next_in_list;
		}
		*lst = NULL;
	}
}
