/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankinzin <ankinzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:19:59 by ankinzin          #+#    #+#             */
/*   Updated: 2023/03/20 20:20:01 by ankinzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t len)
{
	unsigned char	*ptr_dest;
	unsigned char	trans_c;
	size_t			i;

	ptr_dest = dest;
	trans_c = c;
	i = 0;
	while (i < len)
	{
		*ptr_dest = trans_c;
		ptr_dest++;
		i++;
	}
	return (dest);
}
