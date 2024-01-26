/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 09:46:09 by jbidaux           #+#    #+#             */
/*   Updated: 2023/10/18 11:35:17 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newelem;
	t_list	*newlst;

	if (!lst)
		return (0);
	newlst = NULL;
	while (lst)
	{
		newelem = ft_lstnew(f(lst->content));
		if (!newelem)
		{
			ft_lstclear(&newlst, del);
			return (0);
		}
		ft_lstadd_back(&newlst, newelem);
		lst = lst->next;
	}
	return (newlst);
}
