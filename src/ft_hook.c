/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:51:44 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/25 08:50:56 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	update_display(t_game *game, int pos_y, int pos_x)
{
	check_for_item(game, 'C', (pos_y / PIXEL), (pos_x / PIXEL));
	check_for_exit(game, 'E', (pos_y / PIXEL), (pos_x / PIXEL));
	update_display_moves(game, MOVES_POS_X, MOVES_POS_Y);
	update_display_item(game, ITEM_POS_X, ITEM_POS_Y);
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	int		pos_y;
	int		pos_x;

	game = param;
	pos_y = game->player->image->instances[0].y;
	pos_x = game->player->image->instances[0].x;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->game_window);
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		if ((pos_y - PLAYER_STEP >= PIXEL))
			check_move_up(game);
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		if ((pos_y + PLAYER_STEP <= (int)(game->map->height
				- game->player->image->height) - 1))
			check_move_down(game);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		if (pos_x - PLAYER_STEP >= PIXEL)
			check_move_left(game);
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		if (pos_x + PLAYER_STEP <= (int)(game->map->width
			- game->player->image->width) - 1)
			check_move_right(game);
	update_display(game, pos_y, pos_x);
}
