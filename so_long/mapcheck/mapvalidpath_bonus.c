/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapvalidpath_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: about <about@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:59:58 by about             #+#    #+#             */
/*   Updated: 2023/01/26 16:56:04 by about            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	regtangular(void)
{
	write(2, "The map must be rectangular\n", 28);
	exit(1);
}

char	**ft_ptrdup(char **map)
{
	size_t	len;
	char	**dup;

	len = ft_ptrlen(map);
	dup = ft_calloc(len + 1, sizeof(char *));
	if (!dup)
		return (NULL);
	len = 0;
	while (map[len])
	{
		dup[len] = ft_strdup(map[len]);
		len++;
	}
	return (dup);
}

void	check_coll(int y, int x, char **map)
{
	if (map[y][x] == 'P' || map[y][x] == '0' || map[y][x] == 'C')
	{
		map[y][x] = 'X';
		check_coll(y + 1, x, map);
		check_coll(y - 1, x, map);
		check_coll(y, x + 1, map);
		check_coll(y, x - 1, map);
	}
}

void	check_exit(int y, int x, char **map)
{
	if (map[y][x] == 'E' || map[y][x] == 'N' || map[y][x] == 'X')
	{
		map[y][x] = 'x';
		check_exit(y + 1, x, map);
		check_exit(y - 1, x, map);
		check_exit(y, x + 1, map);
		check_exit(y, x - 1, map);
	}
}

void	floodfill_b(t_map *comp)
{
	int		y;
	int		x;
	char	**dup;

	dup = ft_ptrdup(comp->map);
	check_coll(comp->y, comp->x, dup);
	check_exit(comp->y, comp->x, dup);
	y = 0;
	while (dup[y])
	{
		x = 0;
		while (dup[y][x])
		{
			if (dup[y][x] == 'C' || dup[y][x] == 'E')
			{
				write(2, "Map Invalid\n", 12);
				exit(1);
			}
			x++;
		}
		y++;
	}
	ft_free(dup);
}
