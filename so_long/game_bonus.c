/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: about <about@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:25:18 by about             #+#    #+#             */
/*   Updated: 2023/01/26 15:56:44 by about            ###   ########.fr       */
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
	int		y;
	int		x;
	char	*count;

	y = 0;
	while (comp->map[y])
	{
		x = 0;
		while (comp->map[y][x])
		{
			diplaymapwithenemy(coordinat, img, x, y);
			x++;
		}
		y++;
	}
	count = ft_itoa(coordinat->counter);
	mlx_string_put(coordinat->mlx, coordinat->mlxwindow,
		25, 15, 0xCF0A0A, count);
	free(count);
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

void	display_tiles(t_game *coordinat, void *img)
{
	int	x;
	int	y;

	y = 0;
	while (coordinat->map->map[y])
	{
		x = 0;
		while (coordinat->map->map[y][x])
		{
			if (coordinat->map->map[y][x] == 'C')
				mlx_put_image_to_window(coordinat->mlx,
					coordinat->mlxwindow, img, x * SIZE, y * SIZE);
			x++;
		}
		y++;
	}
}

void	mlxwindow_b(t_game *coordinat, t_map *comp, t_img *img)
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
	mlx_loop_hook(coordinat->mlx, collect_animation, coordinat);
	mlx_loop(coordinat->mlx);
}
