/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: about <about@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:25:18 by about             #+#    #+#             */
/*   Updated: 2023/01/25 18:15:08 by about            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	coordinates(t_game *coordinat, t_map *comp)
{
	coordinat->y = ft_ptrlen(comp->map);
	coordinat->x = ft_strlen(comp->map[0]);
}

void	display_map(t_game *coordinat, t_map *comp, t_img *img)
{
	int	y;
	int	x;

	y = 0;
	while (comp->map[y])
	{
		x = 0;
		while (comp->map[y][x])
		{
			if (comp->map[y][x] == '0')
				terrain(coordinat, img, y, x);
			if (comp->map[y][x] == '1')
				wall(coordinat, img, y, x);
			if (comp->map[y][x] == 'E')
				exitt(coordinat, img, y, x);
			if (comp->map[y][x] == 'C')
				collectible(coordinat, img, y, x);
			if (comp->map[y][x] == 'P')
				player(coordinat, img, y, x);
			x++;
		}
		y++;
	}
}

int	key_pressed(int key_code, t_game *coordinat)
{
	if (key_code == 53)
		exit(0);
	if (key_code == 13 || key_code == 126)
		moveup(coordinat);
	else if (key_code == 2 || key_code == 124)
		moveright(coordinat);
	else if (key_code == 0 || key_code == 123)
		moveleft(coordinat);
	else if (key_code == 1 || key_code == 125)
		movedown(coordinat);
	if (coordinat->map->collect == 0)
		exit_change(coordinat);
	return (0);
}

void	mlxwindow(t_game *coordinat, t_map *comp, t_img *img)
{
	int	win_height;
	int	win_width;

	win_height = coordinat->y * SIZE;
	win_width = coordinat->x * SIZE;
	coordinat->mlx = mlx_init();
	coordinat->mlxwindow = mlx_new_window(coordinat->mlx, win_width,
			win_height, "so_long");
	display_map(coordinat, comp, img);
	mlx_hook(coordinat->mlxwindow, 2, 0, key_pressed, coordinat);
	mlx_hook(coordinat->mlxwindow, 17, 0, (void *)exit, 0);
	mlx_loop(coordinat->mlx);
}
