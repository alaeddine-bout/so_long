/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   you_win_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: about <about@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:15:03 by about             #+#    #+#             */
/*   Updated: 2023/01/25 21:45:11 by about            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	invalid(void)
{
	write(1, "Map Invalid", 11);
	exit(1);
}

void	lose(void)
{
	write(1, "\x1B[31mYOU LOSE!!", 15);
	exit(0);
}

void	winn(void)
{
	write(1, "\x1B[32mYOU WIN!!", 14);
	exit(0);
}

void	counter(t_game *coordinat)
{
	void	*img;
	int		i;

	img = mlx_xpm_file_to_image(coordinat->mlx,
			"./assets/wall.xpm", &i, &i);
	mlx_put_image_to_window(coordinat->mlx, coordinat->mlxwindow, img,
		0, 0);
	coordinat->counter += 1;
	mlx_string_put(coordinat->mlx, coordinat->mlxwindow,
		25, 15, 0xCF0A0A, ft_itoa(coordinat->counter));
}
