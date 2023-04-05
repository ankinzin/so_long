/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankinzin <ankinzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:08:48 by ankinzin          #+#    #+#             */
/*   Updated: 2023/03/20 20:08:52 by ankinzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# if OPEN_MAX > 12800
#  define ARRAY_MAX OPEN_MAX
# endif

# if OPEN_MAX <= 12800
#  define ARRAY_MAX 12800
# endif

int		ft_strlen(char *str);
char	*ft_strchr(char *str, int c);
char	*how_to_read(int fd, char *static_buffer);
char	*put_line(char *static_buffer);
char	*new_buffer(char *static_buffer);
char	*get_next_line(int fd);

#endif