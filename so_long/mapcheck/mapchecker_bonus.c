/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchecker_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: about <about@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:51:59 by about             #+#    #+#             */
/*   Updated: 2023/01/26 18:31:07 by about            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	count_items(t_map *comp)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (comp->map[y])
	{
		x = 0;
		while (comp->map[y][x])
		{
			if (comp->map[y][x] == 'C')
				comp->collect += 1;
			if (comp->map[y][x] == 'P')
			{
				comp->pp += 1;
				comp->y = y;
				comp->x = x;
			}
			if (comp->map[y][x] == 'E')
				comp->exit += 1;
			x++;
		}
		y++;
	}
}

void	check_items(t_map *comp)
{
	if (comp->collect <= 0)
	{
		write(2, "collectible must be atleast 1\n", 30);
		exit(1);
	}
	if (comp->pp != 1 || comp->exit != 1)
	{
		write(2, "player or exit must be 1\n", 25);
		exit(1);
	}
}

void	check_others(t_map *comp)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (comp->map[y])
	{
		x = 0;
		while (comp->map[y][x])
		{
			if (comp->map[y][x] != 'E' && comp->map[y][x] != 'C'
				&& comp->map[y][x] != 'P' && comp->map[y][x] != '0'
				&& comp->map[y][x] != '1' && comp->map[y][x] != 'N')
			{
				write(2, "this doesn't look like it belongs here..\n", 41);
				exit(1);
			}
			x++;
		}
	y++;
	}	
}

size_t	ft_ptrlen(char **map)
{
	size_t	len;

	len = 0;
	while (map[len])
		len++;
	return (len);
}

void	check_walls(t_map *comp)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (comp->map[y])
	{
		x = 0;
		while (comp->map[y][x])
		{
			if ((y == 0 || y == ft_ptrlen(comp->map) - 1
					|| x == 0 || x == ft_strlen(comp->map[y]) - 1)
				&& comp->map[y][x] != '1')
			{
				write(2, "The map must be closed/surrounded by walls\n", 43);
				exit(1);
			}
			x++;
		}
		if (comp->map[y + 1] && ft_strlen(comp->map[y])
			!= ft_strlen(comp->map[y + 1]))
			regtangular();
		y++;
	}
}
