/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankinzin <ankinzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:19:26 by ankinzin          #+#    #+#             */
/*   Updated: 2023/03/20 20:19:29 by ankinzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char	*ptr_arr;
	unsigned char	find_c;
	size_t			i;

	ptr_arr = (unsigned char *) arr;
	find_c = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (*ptr_arr == find_c)
			return (ptr_arr);
		ptr_arr++;
		i++;
	}
	return (NULL);
}
