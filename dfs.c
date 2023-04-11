/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankinzin <ankinzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:40:23 by ankinzin          #+#    #+#             */
/*   Updated: 2023/04/03 18:59:45 by ankinzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "./so_long.h"

void	dfs(int x, int y, t_game *game, int **visited)
{
	if (x < 0 || x >= game->hei || y < 0 || y >= game->wid)
		return ;
	visited[x][y] = 1;
	if (game->map[x][y] == 'E')
	{
		game->exit_y = y;
		game->exit_x = x;
		return ;
	}
	if (game->map[x][y] == 'C')
	{
		game->col_cnt++;
		if (game->col_cnt == game->all_col)
			return ;
	}
	if (x > 0 && game->map[x - 1][y] != '1' && !visited[x - 1][y])
		dfs(x - 1, y, game, visited);
	if (x < game->hei - 1 && game->map[x + 1][y] != '1' && !visited[x + 1][y])
		dfs(x + 1, y, game, visited);
	if (y > 0 && game->map[x][y - 1] != '1' && !visited[x][y - 1])
		dfs(x, y - 1, game, visited);
	if (y < game->wid - 1 && game->map[x][y + 1] != '1' && !visited[x][y + 1])
		dfs(x, y + 1, game, visited);
}

void	visit_columns(int **visited, t_game *game, int *indice)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->hei)
	{
		visited[i] = malloc(sizeof(int) * game->wid);
		j = 0;
		while (j < game->wid)
			visited[i][j++] = 0;
		i++;
	}
	*indice = i;
}

void	visit_rows(int **visited, t_game *game, int *indice)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->hei)
	{
		j = 0;
		while (j < game->wid && (game->map[i][j] != 'C' || visited[i][j]))
			j++;
		if (j < game->wid)
		{
			*indice = i;
			break ;
		}
		i++;
	}
	*indice = i;
}

void	check_path_to_exit_and_collectibles(t_game *game)
{
	int	**visited;
	int	i;

	i = 0;
	visited = (int **) malloc(sizeof(int *) * game->hei);
	visit_columns(visited, game, &i);
	dfs(game->player_x, game->player_y, game, visited);
	visit_rows(visited, game, &i);
	if (i < game->hei)
		print_err("Collectible or Exit is not reachable\n");
	else if (game->exit_x == -1 || game->exit_y == -1
		|| !visited[game->exit_x][game->exit_y])
		print_err("Collectible or Exit is not reachable\n");
	i = 0;
	while (i < game->hei)
		free(visited[i++]);
	free(visited);
}
