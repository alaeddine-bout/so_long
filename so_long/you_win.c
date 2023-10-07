/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   you_win.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: about <about@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:15:03 by about             #+#    #+#             */
/*   Updated: 2023/01/24 21:55:15 by about            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	invalid(void)
{
	write(1, "Map Invalid", 11);
	exit(1);
}

void	winn(void)
{
	write(1, "\x1B[32mYOU WIN!!", 14);
	exit(0);
}

void	counter(t_game *coordinat)
{
	coordinat->counter += 1;
	ft_putnbr_fd(coordinat->counter, 1);
	ft_putstr_fd("\n", 1);
}
