/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:51:44 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/24 13:47:24 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	int		posY;
	int		posX;

	game = param;
	posY = game->player->image->instances[0].y;
	posX = game->player->image->instances[0].x;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->game_window);
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		if ((posY - PLAYER_STEP >= PIXEL))
			check_move_up(game);
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		if ((posY + PLAYER_STEP <= (int)(game->map->height
					- game->player->image->height) - 1))
			check_move_down(game);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		if (posX - PLAYER_STEP >= PIXEL)
			check_move_left(game);
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		if (posX + PLAYER_STEP <= (int)(game->map->width
				- game->player->image->width) - 1)
			check_move_right(game);
	check_for_item(game, 'C', (posY / PIXEL), (posX / PIXEL));
	check_for_exit(game, 'E', (posY / PIXEL), (posX / PIXEL));
	update_display_moves(game, MOVES_POS_X, MOVES_POS_Y);
	update_display_item(game, ITEM_POS_X, ITEM_POS_Y);
}
