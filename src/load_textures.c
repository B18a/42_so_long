/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:43:28 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/22 18:08:20 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"



// int	ft_load_textures_item(t_game *game)
// {
// 	int i;

// 	i = 0;
// 	while (i < game->item_total)
// 	{
// 		game->item[i]->texture = mlx_load_png(PATH_ITEM);
// 		game->item[i]->image = mlx_texture_to_image(game->game_window, game->item[i]->texture);
// 		if (!game->item[i]->image)
// 			return (call_exit(game), 0);
// 		if (mlx_image_to_window(game->game_window, game->item[i]->image, game->item[i]->pos->x * PIXEL, game->exit->pos->y * PIXEL))
// 			return (call_exit(game), 0);
// 		i++;
// 		mlx_delete_texture(game->item[i]->texture);
// 	}
// 	return(0);
// }

// int	ft_load_textures_asset(t_game *game, t_asset **asset, const char path[])
// {
// 		int i;

// 		i = 0;
// 		game->item = ft_initialize_asset(game->item_total);

// 		while(i < game->item_total)
// 		{
// 			asset[i]->texture = mlx_load_png(path);
// 			asset[i]->image = mlx_texture_to_image(game->game_window, asset[i]->texture);
// 			// asset[i]->pos = get_pos_unique(game->map->map_as_arr, 'C');

// 			asset[i]->pos->x = 10 + i * 100;
// 			asset[i]->pos->y = 10 + i * 100;
// 			if(!asset[i]->image)
// 				return (call_exit(game), 0);
// 			if(mlx_image_to_window(game->game_window, asset[i]->image, asset[i]->pos->x, asset[i]->pos->y))
// 				return (call_exit(game), 0);
// 			i++;
// 		}
// 		return(0);
// }

// int	ft_load_textures_enemy(t_game *game, const char* paths_enemy[])
// {
// 		int i;

// 		i = 0;

// 		while(i < game->enemy_total)
// 		{
// 			game->enemy[i]->texture = mlx_load_png(paths_enemy[i]);
// 			game->enemy[i]->image = mlx_texture_to_image(game->game_window, game->enemy[i]->texture);
// 			game->enemy[i]->pos->x = 100 + i * 100;
// 			game->enemy[i]->pos->y = 100 + i * 100;
// 			if(!game->enemy[i]->image)
// 				return (call_exit(game), 0);
// 			if(mlx_image_to_window(game->game_window, game->enemy[i]->image, game->enemy[i]->pos->x, game->enemy[i]->pos->y))
// 				return (call_exit(game), 0);
// 			i++;
// 		}
// 		return(0);
// }
