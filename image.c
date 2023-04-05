/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankinzin <ankinzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:09:04 by ankinzin          #+#    #+#             */
/*   Updated: 2023/04/03 11:32:14 by ankinzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

t_img	img_init(void *mlx)
{
	t_img	rt;
	int		wid;
	int		hei;

	rt.space = mlx_xpm_file_to_image(mlx, "./images/space.xpm", &wid, &hei);
	rt.wall = mlx_xpm_file_to_image(mlx, "./images/wall.xpm", &wid, &hei);
	rt.run = mlx_xpm_file_to_image(mlx, "./images/run.xpm", &wid, &hei);
	rt.paper = mlx_xpm_file_to_image(mlx, "./images/paper.xpm", &wid, &hei);
	rt.exit1 = mlx_xpm_file_to_image(mlx, "./images/exit1.xpm", &wid, &hei);
	rt.exit2 = mlx_xpm_file_to_image(mlx, "./images/exit2.xpm", &wid, &hei);
	return (rt);
}

void	put_img(t_game *g, int w, int h)
{
	if (g->str_line[h * g->wid + w] == '1')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.wall, w * 64, h * 64);
	}
	else if (g->str_line[h * g->wid + w] == 'C')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.paper, w * 64, h * 64);
	}
	else if (g->str_line[h * g->wid + w] == 'P')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.run, w * 64, h * 64);
	}
	else if (g->str_line[h * g->wid + w] == 'E' && g->all_col == g->collected)
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.exit2, w * 64, h * 64);
	}
	else if (g->str_line[h * g->wid + w] == 'E')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.exit1, w * 64, h * 64);
	}
	else
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.space, w * 64, h * 64);
	}
}

void	setting_img(t_game *game)
{
	int		hei;
	int		wid;

	hei = 0;
	while (hei < game->hei)
	{
		wid = 0;
		while (wid < game->wid)
		{
			put_img(game, wid, hei);
			wid++;
		}
		hei++;
	}
}
