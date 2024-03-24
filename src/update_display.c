/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 11:43:14 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/24 14:07:38 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	update_display_exit(t_game *game)
{
	game->exit->image_closed->instances->enabled = 0;
	game->exit->image_open->instances->enabled = 1;
}

void	update_display_item(t_game *game, int32_t posX, int32_t posY)
{
	char	*str;

	str = ft_itoa(game->item_collect);
	mlx_delete_image(game->game_window, game->item_image);
	game->item_image = mlx_put_string(game->game_window, str, posX, posY);
	if (str)
		free(str);
	if (game->item_total == game->item_collect)
		update_display_exit(game);
}

void	update_display_moves(t_game *game, int32_t posX, int32_t posY)
{
	char	*str;

	str = ft_itoa(game->player->moves);
	mlx_delete_image(game->game_window, game->player->move_image);
	game->player->move_image = mlx_put_string(game->game_window, str, posX,
			posY);
	if (str)
		free(str);
}
