/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankinzin <ankinzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:19:53 by ankinzin          #+#    #+#             */
/*   Updated: 2023/03/20 20:19:55 by ankinzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;

	if (!dest && !src)
		return (0);
	ptr_dest = (unsigned char *) dest;
	ptr_src = (unsigned char *) src;
	if (src < dest)
		while (n--)
			ptr_dest[n] = ptr_src[n];
	else
		ft_memcpy(ptr_dest, ptr_src, n);
	return (dest);
}
