/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:37:55 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/26 16:47:39 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_collision(void *param)
{
	t_game	*game;
	t_pos	player;
	t_pos	enemy;

	game = (t_game *)param;
	player.y = game->player->image->instances[0].y;
	player.x = game->player->image->instances[0].x;
	enemy.y = game->enemy->image->instances[0].y;
	enemy.x = game->enemy->image->instances[0].x;
	if (player.y == enemy.y && player.x == enemy.x)
		mlx_close_window(game->game_window);
}
