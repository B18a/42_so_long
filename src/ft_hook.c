/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:51:44 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/08 23:34:19 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// void delete_temp_images(t_game *game)
// {
// 	if(game->player->coordinates_x)
// 		mlx_delete_image(game->game_window, game->player->coordinates_x);
// 	if(game->player->coordinates_y)
// 		mlx_delete_image(game->game_window, game->player->coordinates_y);
// 	if(game->player->width)
// 		mlx_delete_image(game->game_window, game->player->width);
// 	if(game->player->height)
// 		mlx_delete_image(game->game_window, game->player->height);
// }


void	update_display_item(t_game *game, int32_t posX, int32_t posY)
{
	char *str;

	str = ft_itoa(game->player->item);
	mlx_delete_image(game->game_window, game->player->item_image);
	game->player->item_image = mlx_put_string(game->game_window,str, posX, posY);
	if(str)
		free(str);
}
void	update_display_moves(t_game *game, int32_t posX, int32_t posY)
{
	char *str;

	str = ft_itoa(game->player->moves);
	mlx_delete_image(game->game_window, game->player->move_image);
	game->player->move_image = mlx_put_string(game->game_window,str, posX, posY);
	if(str)
		free(str);
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		// delete_temp_images(game);
		mlx_close_window(game->game_window);
	}
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS) // One Step per Press
	{
		if (game->player->image->instances[0].y - PLAYER_STEP >= 0)
		{
			game->player->image->instances[0].y -= PLAYER_STEP;
			game->player->moves += 1;
		}
	}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	{
		if (game->player->image->instances[0].y + PLAYER_STEP <= (int)(HEIGHT - game->player->image->height))
		{
			game->player->image->instances[0].y += PLAYER_STEP;
			game->player->moves += 1;
		}
	}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
	{
		if( game->player->image->instances[0].x - PLAYER_STEP >= 0)
		{
			game->player->image->instances[0].x -= PLAYER_STEP;
			game->player->moves += 1;
		}
	}
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
	{
		if (game->player->image->instances[0].x + PLAYER_STEP <= (int)(WIDTH - game->player->image->width))
		{
			game->player->image->instances[0].x += PLAYER_STEP;
			game->player->moves += 1;
		}
	}
	check_collision(game);
	check_collect(game);
	// check_exit(game);
	update_display_moves(game, 300, 100);
	update_display_item(game, 400, 100);

}
