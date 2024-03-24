/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:43:28 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/24 13:47:53 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_load_textures_item(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->item_total)
	{
		game->item[i]->texture = mlx_load_png(PATH_ITEM);
		game->item[i]->image = mlx_texture_to_image(game->game_window,
				game->item[i]->texture);
		if (!game->item[i]->image)
			return (call_exit(game), 0);
		if (mlx_image_to_window(game->game_window, game->item[i]->image,
				game->item[i]->pos->x * PIXEL, game->item[i]->pos->y * PIXEL))
			return (call_exit(game), 0);
		mlx_delete_texture(game->item[i]->texture);
		i++;
	}
	return (0);
}
