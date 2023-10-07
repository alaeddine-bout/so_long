/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playermovement2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: about <about@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 21:09:47 by about             #+#    #+#             */
/*   Updated: 2023/01/24 04:53:34 by about            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moveupmove(t_game *coordinat, void *img, int i)
{
	img = mlx_xpm_file_to_image(coordinat->mlx,
			"./assets/terrain.xpm", &i, &i);
	mlx_put_image_to_window(coordinat->mlx, coordinat->mlxwindow, img,
		coordinat->map->x * SIZE, coordinat->map->y * SIZE);
	img = mlx_xpm_file_to_image(coordinat->mlx,
			"./assets/playerup.xpm", &i, &i);
	mlx_put_image_to_window(coordinat->mlx, coordinat->mlxwindow, img,
		coordinat->map->x * SIZE, (coordinat->map->y - 1) * SIZE);
}

void	moverightmove(t_game *coordinat, void *img, int i)
{
	img = mlx_xpm_file_to_image(coordinat->mlx,
			"./assets/terrain.xpm", &i, &i);
	mlx_put_image_to_window(coordinat->mlx, coordinat->mlxwindow,
		img, coordinat->map->x * SIZE, coordinat->map->y * SIZE);
	img = mlx_xpm_file_to_image(coordinat->mlx,
			"./assets/playerright.xpm", &i, &i);
	mlx_put_image_to_window(coordinat->mlx, coordinat->mlxwindow, img,
		(coordinat->map->x + 1) * SIZE, coordinat->map->y * SIZE);
}

void	moveleftmove(t_game *coordinat, void *img, int i)
{
	img = mlx_xpm_file_to_image(coordinat->mlx,
			"./assets/terrain.xpm", &i, &i);
	mlx_put_image_to_window(coordinat->mlx, coordinat->mlxwindow, img,
		coordinat->map->x * SIZE, coordinat->map->y * SIZE);
	img = mlx_xpm_file_to_image(coordinat->mlx,
			"./assets/playerleft.xpm", &i, &i);
	mlx_put_image_to_window(coordinat->mlx, coordinat->mlxwindow, img,
		(coordinat->map->x - 1) * SIZE, coordinat->map->y * SIZE);
}

void	movedownmove(t_game *coordinat, void *img, int i)
{
	img = mlx_xpm_file_to_image(coordinat->mlx,
			"./assets/terrain.xpm", &i, &i);
	mlx_put_image_to_window(coordinat->mlx, coordinat->mlxwindow, img,
		coordinat->map->x * SIZE, coordinat->map->y * SIZE);
	img = mlx_xpm_file_to_image(coordinat->mlx,
			"./assets/playerdown.xpm", &i, &i);
	mlx_put_image_to_window(coordinat->mlx, coordinat->mlxwindow, img,
		coordinat->map->x * SIZE, (coordinat->map->y + 1) * SIZE);
}
