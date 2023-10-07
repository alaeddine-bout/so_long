/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: about <about@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:52:35 by about             #+#    #+#             */
/*   Updated: 2023/01/26 16:56:41 by about            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include<mlx.h>
# include<stdio.h>
# include"get_next_line.h"
# include"./libft/libft.h"

# define SIZE 62
# define COIN1 "assets/coinface.xpm"
# define COIN2 "assets/coinjenb.xpm"
# define COIN3 "assets/coinface2.xpm"
# define COIN4 "assets/coinjenblissr.xpm"

typedef struct t_map {
	int		collect;
	int		exit;
	int		pp;
	int		space;
	int		walls;
	int		y;
	int		x;
	char	**map;

}	t_map;

typedef struct t_game {
	int		y;
	int		x;
	int		counter;
	void	*mlx;
	void	*mlxwindow;
	t_map	*map;
}	t_game;

typedef struct t_img {
	void	*img_terr;
	void	*img_wall;
	void	*img_exit;
	void	*img_collect;
	void	*img_player;
	void	*img_enemy;
	char	*path;
	t_game	*coordinat;
}	t_img;

void	count_items(t_map *comp);
void	check_items(t_map *comp);
void	check_others(t_map *comp);
void	check_walls(t_map *comp);
size_t	ft_ptrlen(char **map);
void	regtangular(void);
char	**ft_ptrdup(char **map);
void	floodfill(t_map*comp);
void	floodfill_b(t_map *comp);
void	mlxwindow(t_game *cordinates, t_map *comp, t_img *img);
void	mlxwindow_b(t_game *cordinates, t_map *comp, t_img *img);
void	coordinates(t_game *cordinates, t_map *comp);
void	moveup(t_game *coordinat);
void	moveright(t_game *coordinat);
void	moveleft(t_game *coordinat);
void	movedown(t_game *coordinat);
void	exit_change(t_game *coordinat);
void	terrain(t_game *coordinat, t_img *img, int y, int x);
void	wall(t_game *coordinat, t_img *img, int y, int x);
void	collectible(t_game *coordinat, t_img *img, int y, int x);
void	collectible_b(t_game *coordinat, t_img *img, int y, int x);
void	player(t_game *coordinat, t_img *img, int y, int x);
void	exitt(t_game *coordinat, t_img *img, int y, int x);
void	enemy(t_game *coordinat, t_img *img, int y, int x);
void	moveupmove(t_game *coordinat, void *img, int i);
void	moverightmove(t_game *coordinat, void *img, int i);
void	moveleftmove(t_game *coordinat, void *img, int i);
void	movedownmove(t_game *coordinat, void *img, int i);
void	winn(void);
void	counter(t_game *coordinat);
void	ft_free(char **map);
void	invalid(void);
void	diplaymapwithenemy(t_game *coordinat, t_img *img, int x, int y);
void	display_map(t_game *coordinat, t_map *comp, t_img *img);
int		collect_animation(t_game *coordinat);
void	display_tiles(t_game *coordinat, void *img);
void	lose(void);

#endif