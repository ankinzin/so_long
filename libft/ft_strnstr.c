/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankinzin <ankinzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:22:03 by ankinzin          #+#    #+#             */
/*   Updated: 2023/03/20 20:22:05 by ankinzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *s1, char *s2, int n)
{
	char	*ptr_s1;
	int		i;

	ptr_s1 = (char *)s1;
	i = 0;
	if (ft_strlen(s2) == 0)
		return (ptr_s1);
	if (n > ft_strlen(s1))
		n = ft_strlen(s1);
	while (i < n)
	{
		if (ft_strncmp(&s1[i], s2, ft_strlen(s2)) == 0)
		{
			if (i + ft_strlen(s2) > n)
				return (NULL);
			return (ptr_s1);
		}
		ptr_s1++;
		i++;
	}
	return (NULL);
}
