/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankinzin <ankinzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:11:41 by ankinzin          #+#    #+#             */
/*   Updated: 2023/04/03 18:25:05 by ankinzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	map_read(char *filename, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		print_err("File open fail.\n");
	line = get_next_line(fd);
	game->hei = 0;
	game->wid = ft_strlen(line) - 1;
	game->str_line = ft_strdup_without_newline(line);
	while (line)
	{
		free(line);
		game->hei++;
		line = get_next_line(fd);
		if (line)
			game->str_line = ft_strjoin_without_newline(game->str_line, line);
	}
	close(fd);
}

void	map_grid(char *filename, t_game *game)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		print_err("File open fail.\n");
	game->map = ft_calloc(sizeof(char *), game->hei + 1);
	count = 0;
	while (count < game->hei)
	{
		line = get_next_line(fd);
		game->map[count] = ft_strdup_without_newline(line);
		if (line)
			free(line);
		count++;
	}
	close(fd);
}

void	ft_player_pos(t_game *game)
{
	int	right;
	int	down;

	down = 0;
	while (down < game->hei)
	{
		right = 0;
		while (right < game->wid)
		{
			if (game->map[down][right] == 'P')
			{
				game->player_x = down;
				game->player_y = right;
			}
			right++;
		}
		down++;
	}
}
