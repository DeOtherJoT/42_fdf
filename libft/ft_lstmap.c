/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:30:14 by jthor             #+#    #+#             */
/*   Updated: 2021/10/06 21:06:09 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*node;

	node = ft_lstnew(f(lst->content));
	if (!node)
		return (NULL);
	ret = node;
	lst = lst->next;
	while (lst)
	{
		node->next = ft_lstnew(f(lst->content));
		if (!(node->next))
		{
			ft_lstclear(&ret, del);
			return (NULL);
		}
		node = node->next;
		lst = lst->next;
	}
	return (ret);
}
