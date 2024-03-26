/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:49:16 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/26 16:06:15 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_enemy(void *param)
{
	t_game	*game;
	int		nbr;

	game = (t_game *)param;
	game->enemy_frame += 1;
	if (game->frame == FRAME * 1)
	{
		nbr = random_nbr_range(1, 2);
		ft_printf("NBR X IS %i\n", nbr);
		ft_printf("MAP [%i][%i]\n", game->map->height / PIXEL, game->map->width / PIXEL);
		if (nbr == 1)
		{
			game->enemy->image->instances[0].x += PLAYER_STEP;
		}
		if (nbr == 2)
		{
			game->enemy->image->instances[0].x -= PLAYER_STEP;
		}
	}
	if (game->frame == FRAME * 2)
	{
		nbr = random_nbr_range(1, 2);
		ft_printf("NBR Y IS %i\n", nbr);
		if (nbr == 1)
		{
			game->enemy->image->instances[0].y += PLAYER_STEP;
		}
		if (nbr == 2)
		{
			game->enemy->image->instances[0].y -= PLAYER_STEP;
		}
	}
}
