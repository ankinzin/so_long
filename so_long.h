/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankinzin <ankinzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:10:17 by ankinzin          #+#    #+#             */
/*   Updated: 2023/04/03 18:24:58 by ankinzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include "./get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3

# define X_EVENT_KEY_EXIT		17
# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct s_img 
{
	void	*run;
	void	*paper;
	void	*space;
	void	*exit1;
	void	*exit2;
	void	*wall;
}				t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	img;
	int		wid;
	int		hei;
	char	*str_line;
	char	**map;
	int		all_col;
	int		col_cnt;
	int		collected;
	int		walk_cnt;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
}				t_game;

/*
	utils.c
*/
char	*ft_strdup_without_newline(char *s);
int		ft_strlcpy_without_newline(char *dst, char *src, int len);
char	*ft_strjoin_without_newline(char *s1, char *s2);

/*
	image.c
*/
t_img	img_init(void *mlx);
void	put_img(t_game *g, int w, int h);
void	setting_img(t_game *game);

/*
	map_read.c
*/
void	map_read(char *filename, t_game *game);
void	map_grid(char *filename, t_game *game);
void	ft_player_pos(t_game *game);
/*
	dfs.c
*/
void	map_check_clear_path(t_game *game);
void check_path_to_exit_and_collectibles(t_game *game);
int get_player_pos(t_game *game);

/*
	map.c
*/
void	map_check_wall(t_game *game);
void	map_check_params(t_game *game);
void	map_check(t_game *game);
void check_valid_map(t_game *game);

/*
	key.c
*/
int		clear_game(t_game *game);
void	move_w(t_game *g);
void	move_a(t_game *g);
void	move_s(t_game *g);
void	move_d(t_game *g);

/*
	so_long.c
*/
void	print_err(char *message);
void	game_init(t_game *g, char *map);
int		exit_game(t_game *game);
int		press_key(int key_code, t_game *game);
int		main(int ac, char *av[]);

#endif