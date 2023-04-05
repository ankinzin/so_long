/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankinzin <ankinzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:16:31 by ankinzin          #+#    #+#             */
/*   Updated: 2023/03/20 20:16:34 by ankinzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *str, size_t n)
{
	unsigned char	*ptr_str;
	size_t			i;

	ptr_str = str;
	i = 0;
	while (i < n)
	{
		*ptr_str = 0;
		ptr_str++;
		i++;
	}
	return (str);
}
