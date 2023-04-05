/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankinzin <ankinzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:19:04 by ankinzin          #+#    #+#             */
/*   Updated: 2023/03/20 20:19:06 by ankinzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_mem;

	new_mem = NULL;
	new_mem = (t_list *)malloc(sizeof(t_list));
	if (!(new_mem))
		return (NULL);
	new_mem->content = content;
	new_mem->next = NULL;
	return (new_mem);
}
