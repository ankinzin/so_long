/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankinzin <ankinzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:22:09 by ankinzin          #+#    #+#             */
/*   Updated: 2023/03/20 20:22:11 by ankinzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int c)
{
	char	*ptr_str;
	char	to_find;
	int		i;

	ptr_str = (char *)str;
	to_find = (char)c;
	i = ft_strlen(str);
	if (to_find == '\0')
		return (&ptr_str[i]);
	while (i >= 0)
	{
		if (ptr_str[i] == to_find)
			return (&ptr_str[i]);
		i--;
	}
	return (NULL);
}
