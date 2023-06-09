/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankinzin <ankinzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:19:19 by ankinzin          #+#    #+#             */
/*   Updated: 2023/03/20 20:19:21 by ankinzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;
	size_t			i;

	ptr_dest = (unsigned char *) dest;
	ptr_src = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		*ptr_dest = *ptr_src;
		if (*ptr_dest == (unsigned char)c)
			return (++ptr_dest);
		ptr_dest++;
		ptr_src++;
		i++;
	}
	return (NULL);
}
