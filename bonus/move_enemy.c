/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:49:16 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/26 17:01:15 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	enemy_right(t_game *game)
{
	if (game->enemy->image->instances[0].x + PLAYER_STEP < game->map->width)
		game->enemy->image->instances[0].x += PLAYER_STEP;
}
static void	enemy_left(t_game *game)
{
	if (game->enemy->image->instances[0].x - PLAYER_STEP > 0)
		game->enemy->image->instances[0].x -= PLAYER_STEP;
}

static void	enemy_up(t_game *game)
{
	if (game->enemy->image->instances[0].y + PLAYER_STEP < game->map->height)
		game->enemy->image->instances[0].y += PLAYER_STEP;
}
static void	enemy_down(t_game *game)
{
	if (game->enemy->image->instances[0].y - PLAYER_STEP > 0)
		game->enemy->image->instances[0].y -= PLAYER_STEP;
}

void	move_enemy(void *param)
{
	t_game	*game;
	int		nbr;

	game = (t_game *)param;
	if (game->enemy_frame == FRAME / 2 )
	{
		srand(time(NULL));
		nbr = random_nbr_range(1, 2);
		if (nbr == 1)
			enemy_right(game);
		if (nbr == 2)
			enemy_left(game);
	}
	if (game->enemy_frame == FRAME)
	{
		srand(time(NULL));
		nbr = random_nbr_range(1, 2);
		if (nbr == 1)
			enemy_down(game);
		if (nbr == 2)
			enemy_up(game);
		game->enemy_frame = 0;
	}
	game->enemy_frame += 1;
}
