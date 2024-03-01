/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:43:28 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/01 23:21:00 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// void	ft_load_textures(t_game *game, const char* paths_assets[])
// {
// 	int i;

// 	i = 0;
// 	while(i < AMOUNT_ASSETS)
// 	{
// 		game->assets[i]->texture = mlx_load_png(paths_assets[i]);
// 		game->assets[i]->image = mlx_texture_to_image(game->game_window, game->assets[i]->texture);
// 		mlx_image_to_window(game->game_window, game->assets[i]->image, game->assets[i]->pos->x, game->assets[i]->pos->y);
// 		i++;
// 	}
// }