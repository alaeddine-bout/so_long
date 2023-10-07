/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: about <about@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:04:48 by about             #+#    #+#             */
/*   Updated: 2023/01/24 23:13:41 by about            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	ini(t_map *comp, t_game *coordinat)
{
	comp->collect = 0;
	comp->exit = 0;
	comp->space = 0;
	comp->walls = 0;
	comp->pp = 0;
	coordinat->counter = 0;
}

char	**readmap(char *map)
{
	int		fd;
	char	*str;
	char	*tmp;
	char	**a;

	str = NULL;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (perror("Error :"), exit(1), NULL);
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		if (tmp[0] == '\n')
			invalid();
		str = ft_str_join(str, tmp);
		free(tmp);
	}
	if (!str || str[ft_strlen(str) - 1] == '\n')
		return (free(str), invalid(), NULL);
	return (a = ft_split(str, '\n'), free(str), a);
}

void	ft_free(char **map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		free(map[y]);
		y++;
	}
	free(map);
}

void	checkmap_name(char *map)
{
	if (ft_strncmp(&map[ft_strlen(map) - 4], ".ber", 4))
	{
		write(2, "map must be in '.ber' format", 26);
		exit(1);
	}
}

int	main(int ac, char **av)
{
	t_map	comp;
	t_game	coordinat;
	t_img	img;

	if (ac != 2)
		return (1);
	ini(&comp, &coordinat);
	checkmap_name(av[1]);
	comp.map = readmap(av[1]);
	count_items(&comp);
	check_items(&comp);
	check_others(&comp);
	check_walls(&comp);
	floodfill(&comp);
	coordinates(&coordinat, &comp);
	coordinat.map = &comp;
	mlxwindow(&coordinat, &comp, &img);
}
