/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:43:28 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/08 11:23:36 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_load_textures(t_game *game, const char* paths_assets[])
{
		int i;

		i = 0;
		game->player->texture = mlx_load_png(PATH_PLAYER);
		game->player->image = mlx_texture_to_image(game->game_window, game->player->texture);
		game->player->pos->x = 100;
		game->player->pos->y = 100;
		if(!game->player->image)
			return (call_exit(game), 0);
		if(mlx_image_to_window(game->game_window, game->player->image, game->player->pos->x, game->player->pos->y))
			return (call_exit(game), 0);
		while(i < AMOUNT_ASSETS)
		{
			game->assets[i]->texture = mlx_load_png(paths_assets[i]);
			game->assets[i]->image = mlx_texture_to_image(game->game_window, game->assets[i]->texture);
			game->assets[i]->pos->x = 100 + i * 100;
			game->assets[i]->pos->y = 100 + i * 100;
			if(!game->assets[i]->image)
				return (call_exit(game), 0);
			if(mlx_image_to_window(game->game_window, game->assets[i]->image, game->assets[i]->pos->x, game->assets[i]->pos->y))
				return (call_exit(game), 0);
			i++;
		}
		return(0);
}