/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displaymap+enemy_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: about <about@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 22:48:11 by about             #+#    #+#             */
/*   Updated: 2023/01/26 16:04:05 by about            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	collect_animation(t_game *coordinat)
{
	static int	img_count;
	static int	count;
	void		*img;
	int			i;

	if (count++ < 1500)
		return (0);
	if (img_count == 0)
		img = mlx_xpm_file_to_image(coordinat->mlx, COIN1, &i, &i);
	else if (img_count == 1)
		img = mlx_xpm_file_to_image(coordinat->mlx, COIN2, &i, &i);
	else if (img_count == 2)
		img = mlx_xpm_file_to_image(coordinat->mlx, COIN3, &i, &i);
	else
		img = mlx_xpm_file_to_image(coordinat->mlx, COIN4, &i, &i);
	display_tiles(coordinat, img);
	if (img_count == 3)
		img_count = 0;
	else
		img_count++;
	count = 0;
	return (0);
}

void	enemy(t_game *coordinat, t_img *img, int y, int x)
{
	int	i;

	img->img_enemy = mlx_xpm_file_to_image(coordinat->mlx,
			"./assets/enemy.xpm", &i, &i);
	mlx_put_image_to_window(coordinat->mlx, coordinat->mlxwindow,
		img->img_enemy, x * SIZE, y * SIZE);
}

void	diplaymapwithenemy(t_game *coordinat, t_img *img, int x, int y)
{
	if (coordinat->map->map[y][x] == '0')
		terrain(coordinat, img, y, x);
	if (coordinat->map->map[y][x] == '1')
		wall(coordinat, img, y, x);
	if (coordinat->map->map[y][x] == 'E')
		exitt(coordinat, img, y, x);
	if (coordinat->map->map[y][x] == 'C')
		collectible_b(coordinat, img, y, x);
	if (coordinat->map->map[y][x] == 'P')
		player(coordinat, img, y, x);
	if (coordinat->map->map[y][x] == 'N')
		enemy(coordinat, img, y, x);
}
