/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankinzin <ankinzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:16:43 by ankinzin          #+#    #+#             */
/*   Updated: 2023/03/20 20:16:45 by ankinzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	char	*new_mem;
	size_t	length;

	new_mem = NULL;
	length = size * n;
	if (length == 0)
	{
		new_mem = malloc(0);
		return (new_mem);
	}
	if (length / n != size || length % size != 0)
		return (NULL);
	new_mem = malloc(length);
	if (!(new_mem))
		return (NULL);
	ft_bzero(new_mem, length);
	return (new_mem);
}
