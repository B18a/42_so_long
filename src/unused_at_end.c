/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unused_at_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:54:21 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/25 16:29:50 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_show_address(t_game *game)
{
	ft_printf("game		%p\n", (void *)&game);
	ft_printf("game.image	%p\n", (void *)&game->game_image);
	ft_printf("game.window	%p\n", (void *)&game->game_window);
}

void	print_2d_arr(char **map_in_arr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_printf("	[0][1][2][3][4][5][6][7][8][9][10]\n");
	while (map_in_arr[i])
	{
		ft_printf("[%i]	", i);
		while (map_in_arr[i][j])
		{
			ft_printf(" %c ", map_in_arr[i][j]);
			j++;
		}
		ft_printf("\n");
		j = 0;
		i++;
	}
}
