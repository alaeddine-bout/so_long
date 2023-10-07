/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displaymap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: about <about@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:29:15 by about             #+#    #+#             */
/*   Updated: 2023/01/25 22:17:07 by about            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	terrain(t_game *coordinat, t_img *img, int y, int x)
{
	int	i;

	img->img_terr = mlx_xpm_file_to_image(coordinat->mlx,
			"./assets/terrain.xpm", &i, &i);
	if (!img->img_terr)
	{
		write(1, "xmp error\n", 10);
		exit(0);
	}
	mlx_put_image_to_window(coordinat->mlx, coordinat->mlxwindow,
		img->img_terr, x * SIZE, y * SIZE);
}

void	wall(t_game *coordinat, t_img *img, int y, int x)
{
	int	i;

	img->img_wall = mlx_xpm_file_to_image(coordinat->mlx,
			"./assets/wall.xpm", &i, &i);
	if (!img->img_wall)
	{
		write(1, "xmp error\n", 10);
		exit(0);
	}
	mlx_put_image_to_window(coordinat->mlx, coordinat->mlxwindow,
		img->img_wall, x * SIZE, y * SIZE);
}

void	exitt(t_game *coordinat, t_img *img, int y, int x)
{
	int	i;

	img->img_exit = mlx_xpm_file_to_image(coordinat->mlx,
			"./assets/exit.xpm", &i, &i);
	if (!img->img_exit)
	{
		write(1, "xmp error\n", 10);
		exit(0);
	}
	mlx_put_image_to_window(coordinat->mlx, coordinat->mlxwindow,
		img->img_exit, x * SIZE, y * SIZE);
}

void	collectible(t_game *coordinat, t_img *img, int y, int x)
{
	int	i;

	img->img_collect = mlx_xpm_file_to_image(coordinat->mlx,
			"./assets/collectible.xpm", &i, &i);
	if (!img->img_collect)
	{
		write(1, "xmp error\n", 10);
		exit(0);
	}
	mlx_put_image_to_window(coordinat->mlx, coordinat->mlxwindow,
		img->img_collect, x * SIZE, y * SIZE);
}

void	player(t_game *coordinat, t_img *img, int y, int x)
{
	int	i;

	img->img_player = mlx_xpm_file_to_image(coordinat->mlx,
			"./assets/playerdown.xpm", &i, &i);
	if (!img->img_player)
	{
		write(1, "xmp error\n", 10);
		exit(0);
	}
	mlx_put_image_to_window(coordinat->mlx, coordinat->mlxwindow,
		img->img_player, x * SIZE, y * SIZE);
	coordinat->map->map[y][x] = '0';
}
