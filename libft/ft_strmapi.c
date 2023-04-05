/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankinzin <ankinzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:21:52 by ankinzin          #+#    #+#             */
/*   Updated: 2023/03/20 20:21:53 by ankinzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char *s, char (*f)(unsigned int, char))
{
	char			*new_mem;
	unsigned int	len;
	unsigned int	i;

	new_mem = NULL;
	if (s == 0 || f == 0)
		return (NULL);
	len = ft_strlen(s);
	new_mem = (char *)malloc(sizeof(char) * (len + 1));
	if (!(new_mem))
		return (NULL);
	new_mem[len] = 0;
	i = 0;
	while (i < len)
	{
		new_mem[i] = f(i, s[i]);
		i++;
	}
	return (new_mem);
}
