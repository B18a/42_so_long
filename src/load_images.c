/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:43:28 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/21 14:31:23 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_load_textures_player(t_game *game, int posX, int posY)
{
		game->player->texture = mlx_load_png(PATH_PLAYER);
		game->player->image = mlx_texture_to_image(game->game_window, game->player->texture);
		// game->player->texture_up = mlx_load_png(PATH_PLAYER_UP);
		// game->player->texture_down = mlx_load_png(PATH_PLAYER_DOWN);
		// game->player->image_up = mlx_texture_to_image(game->game_window, game->player->texture_up);
		// game->player->image_down = mlx_texture_to_image(game->game_window, game->player->texture_down);
		game->player->pos->x = posX;
		game->player->pos->y = posY;
		if(!game->player->image)
			return (call_exit(game), 0);
		if(mlx_image_to_window(game->game_window, game->player->image, game->player->pos->x, game->player->pos->y))
			return (call_exit(game), 0);
		return(0);
}

int	ft_load_textures_unique(t_game *game, mlx_image_t *image ,t_pos pos, const char *path)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	image = mlx_texture_to_image(game->game_window, texture);
	if(!image)
		return (call_exit(game), 0);
	if(mlx_image_to_window(game->game_window, image, pos.x * PIXEL, pos.y * PIXEL))
		return (call_exit(game), 0);
	return(0);
}

// int	ft_load_textures_exit(t_game *game, int posX, int posY)
// {
// 	game->exit->texture = mlx_load_png(PATH_EXIT);
// 	game->exit->image = mlx_texture_to_image(game->game_window, game->exit->texture);
// 	game->exit->pos->x = posX;
// 	game->exit->pos->y = posY;
// 	if(!game->exit->image)
// 		return (call_exit(game), 0);

// 	// if(mlx_image_to_window(game->game_window, game->exit->image, game->exit->pos->x, game->exit->pos->y))
// 	if(mlx_image_to_window(game->game_window, game->exit->image, posX, posY))
// 		return (call_exit(game), 0);
// 	return(0);
// }

int	ft_load_textures_asset(t_game *game, t_asset **asset, const char* path[], int amount, t_pos pos)
{
		int i;

		i = 0;
		while(i < amount)
		{
			asset[i]->texture = mlx_load_png(path[i]);
			asset[i]->image = mlx_texture_to_image(game->game_window, asset[i]->texture);
			asset[i]->pos->x = pos.x + i * 100;
			asset[i]->pos->y = pos.y + i * 100;
			if(!asset[i]->image)
				return (call_exit(game), 0);
			if(mlx_image_to_window(game->game_window, asset[i]->image, asset[i]->pos->x, asset[i]->pos->y))
				return (call_exit(game), 0);
			i++;
		}
		return(0);
}
int	ft_load_textures_enemy(t_game *game, const char* paths_enemy[])
{
		int i;

		i = 0;

		while(i < game->enemy_total)
		{
			game->enemy[i]->texture = mlx_load_png(paths_enemy[i]);
			game->enemy[i]->image = mlx_texture_to_image(game->game_window, game->enemy[i]->texture);
			game->enemy[i]->pos->x = 100 + i * 100;
			game->enemy[i]->pos->y = 100 + i * 100;
			if(!game->enemy[i]->image)
				return (call_exit(game), 0);
			if(mlx_image_to_window(game->game_window, game->enemy[i]->image, game->enemy[i]->pos->x, game->enemy[i]->pos->y))
				return (call_exit(game), 0);
			i++;
		}
		return(0);
}
