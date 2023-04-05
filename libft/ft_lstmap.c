/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankinzin <ankinzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:18:57 by ankinzin          #+#    #+#             */
/*   Updated: 2023/03/20 20:18:59 by ankinzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_mem;
	t_list	*now;

	if (lst == NULL || f == NULL)
		return (0);
	new_mem = NULL;
	while (lst)
	{
		now = ft_lstnew((*f)(lst->content));
		if (!(now))
		{
			ft_lstclear(&now, del);
			return (NULL);
		}
		ft_lstadd_back(&new_mem, now);
		lst = lst->next;
	}
	return (new_mem);
}
