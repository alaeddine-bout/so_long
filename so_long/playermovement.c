/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playermovement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: about <about@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:37:03 by about             #+#    #+#             */
/*   Updated: 2023/01/25 04:09:24 by about            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moveup(t_game *coordinat)
{
	void	*img;
	int		i;

	i = 62;
	if (coordinat->map->map[coordinat->map->y - 1][coordinat->map->x] == '0'
		|| coordinat->map->map[coordinat->map->y - 1]
			[coordinat->map->x] == 'C')
	{
		moveupmove(coordinat, &img, i);
		if (coordinat->map->map[coordinat->map->y - 1][coordinat->map->x]
			== 'C')
		{
			coordinat->map->collect--;
			coordinat->map->map[coordinat->map->y - 1][coordinat->map->x]
				= '0';
		}
		coordinat->map->y--;
		counter(coordinat);
	}
	else if (coordinat->map->map[coordinat->map->y - 1][coordinat->map->x]
		== 'E' && !coordinat->map->collect)
		winn();
}

void	moveright(t_game *coordinat)
{
	void	*img;
	int		i;

	i = 62;
	if (coordinat->map->map[coordinat->map->y][coordinat->map->x + 1] == '0'
		|| coordinat->map->map[coordinat->map->y]
			[coordinat->map->x + 1] == 'C')
	{
		moverightmove(coordinat, &img, i);
		if (coordinat->map->map[coordinat->map->y][coordinat->map->x + 1]
			== 'C')
		{
			coordinat->map->collect--;
			coordinat->map->map[coordinat->map->y][coordinat->map->x + 1]
				= '0';
		}
		coordinat->map->x++;
		counter(coordinat);
	}
	else if (coordinat->map->map[coordinat->map->y][coordinat->map->x + 1]
		== 'E'
		&& !coordinat->map->collect)
		winn();
}

void	moveleft(t_game *coordinat)
{
	void	*img;
	int		i;

	i = 62;
	if (coordinat->map->map[coordinat->map->y][coordinat->map->x - 1] == '0'
		|| coordinat->map->map[coordinat->map->y]
			[coordinat->map->x - 1] == 'C')
	{
		moveleftmove(coordinat, &img, i);
		if (coordinat->map->map[coordinat->map->y][coordinat->map->x - 1]
			== 'C')
		{
			coordinat->map->collect--;
			coordinat->map->map[coordinat->map->y][coordinat->map->x - 1]
				= '0';
		}
		coordinat->map->x--;
		counter(coordinat);
	}
	else if (coordinat->map->map[coordinat->map->y][coordinat->map->x - 1]
		== 'E' && !coordinat->map->collect)
		winn();
}

void	movedown(t_game *coordinat)
{
	void	*img;
	int		i;

	i = 62;
	if (coordinat->map->map[coordinat->map->y + 1][coordinat->map->x] == '0'
		|| coordinat->map->map[coordinat->map->y + 1]
			[coordinat->map->x] == 'C')
	{
		movedownmove(coordinat, &img, i);
		if (coordinat->map->map[coordinat->map->y + 1][coordinat->map->x]
			== 'C')
		{
			coordinat->map->collect--;
			coordinat->map->map[coordinat->map->y + 1][coordinat->map->x]
				= '0';
		}
		coordinat->map->y++;
		counter(coordinat);
	}
	else if (coordinat->map->map[coordinat->map->y + 1][coordinat->map->x]
		== 'E' && !coordinat->map->collect)
		winn();
}

void	exit_change(t_game *coordinat)
{
	int		i;
	int		y;
	int		x;
	void	*img;

	i = 62;
	y = 0;
	while (coordinat->map->map[y])
	{
		x = 0;
		while (coordinat->map->map[y][x])
		{
			if (coordinat->map->map[y][x] == 'E')
			{
				img = mlx_xpm_file_to_image(coordinat->mlx,
						"./assets/exit2.xpm", &i, &i);
				mlx_put_image_to_window(coordinat->mlx,
					coordinat->mlxwindow, img, x * SIZE, y * SIZE);
			}
			x++;
		}
		y++;
	}
}
