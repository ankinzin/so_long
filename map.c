/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankinzin <ankinzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:09:41 by ankinzin          #+#    #+#             */
/*   Updated: 2023/04/03 18:36:46 by ankinzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	map_check_wall(t_game *game)
{
	int		i;

	i = 0;
	while (i < ft_strlen(game->str_line))
	{
		if (i < game->wid)
		{
			if (game->str_line[i] != '1')
				print_err("Map must be closed/surrounded by walls\n");
		}
		else if (i % game->wid == 0 || i % game->wid == game->wid - 1)
		{
			if (game->str_line[i] != '1')
				print_err("Map must be closed/surrounded by walls\n");
		}
		else if (i > ft_strlen(game->str_line) - game->wid)
		{
			if (game->str_line[i] != '1')
				print_err("Map must be closed/surrounded by walls\n");
		}
		i++;
	}
}

void	map_check_params(t_game *game)
{
	int	i;
	int	num_e;
	int	num_p;

	i = 0;
	num_e = 0;
	num_p = 0;
	game->all_col = 0;
	game->col_cnt = 0;
	while (i++ < ft_strlen(game->str_line))
	{
		if (game->str_line[i] == 'E')
			num_e++;
		else if (game->str_line[i] == 'P')
			num_p++;
		else if (game->str_line[i] == 'C')
			game->all_col++;
	}
	if (num_e == 0)
		print_err("Map must have at least one exit\n");
	if (game->all_col == 0)
		print_err("Map must have at least one collectible\n");
	if (num_p != 1)
		print_err("Map must have one starting position\n");
}

void	check_valid_map(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < game->hei)
	{
		j = 0;
		while (j < game->wid)
		{
			if (game->map[i][j] != '0' && game->map[i][j] != '1' &&
				game->map[i][j] != 'P' && game->map[i][j] != 'C' &&
				game->map[i][j] != 'E')
			{
				print_err("Invalid character in the map\n");
				return ;
			}
			j++;
		}
		i++;
	}
}

void	map_check(t_game *game)
{
	if (game->hei * game->wid != ft_strlen(game->str_line))
		print_err("Map must be rectangular.\n");
	map_check_wall(game);
	map_check_params(game);
	check_valid_map(game);
	check_path_to_exit_and_collectibles(game);
}
