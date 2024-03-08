/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:43:28 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/08 20:49:46 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


int	ft_load_textures_player(t_game *game)
{
		game->player->texture = mlx_load_png(PATH_PLAYER);
		game->player->image = mlx_texture_to_image(game->game_window, game->player->texture);
		// game->player->texture_up = mlx_load_png(PATH_PLAYER_UP);
		// game->player->texture_down = mlx_load_png(PATH_PLAYER_DOWN);
		// game->player->image_up = mlx_texture_to_image(game->game_window, game->player->texture_up);
		// game->player->image_down = mlx_texture_to_image(game->game_window, game->player->texture_down);
		game->player->pos->x = 50;
		game->player->pos->y = 0;
		if(!game->player->image)
			return (call_exit(game), 0);
		if(mlx_image_to_window(game->game_window, game->player->image, game->player->pos->x, game->player->pos->y))
			return (call_exit(game), 0);
		return(0);
}


int	ft_load_textures_asset(t_game *game, const char* paths_asset[])
{
		int i;

		i = 0;

		while(i < AMOUNT_ENEMY)
		{
			game->asset[i]->texture = mlx_load_png(paths_asset[i]);
			game->asset[i]->image = mlx_texture_to_image(game->game_window, game->asset[i]->texture);
			game->asset[i]->pos->x = 100 + i * 100;
			game->asset[i]->pos->y = 100 + i * 100;
			if(!game->asset[i]->image)
				return (call_exit(game), 0);
			if(mlx_image_to_window(game->game_window, game->asset[i]->image, game->asset[i]->pos->x, game->asset[i]->pos->y))
				return (call_exit(game), 0);
			i++;
		}
		return(0);
}