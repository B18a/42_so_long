/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:43:28 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/27 10:15:37 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_load_textures_item(t_game *game)
{
	int	i;
	int	pos_y;
	int	pos_x;

	i = 0;
	while (i < game->item_total)
	{
		game->item[i]->texture = mlx_load_png(PATH_ITEM);
		if (!game->item[i]->texture)
			return (call_exit(game), 0);
		game->item[i]->image = mlx_texture_to_image(game->game_window,
				game->item[i]->texture);
		if (!game->item[i]->image)
			return (call_exit(game), 0);
		pos_y = game->item[i]->pos->y * PIXEL;
		pos_x = game->item[i]->pos->x * PIXEL;
		if (mlx_image_to_window(game->game_window, game->item[i]->image, pos_x,
				pos_y) == -1)
			return (call_exit(game), 0);
		mlx_delete_texture(game->item[i]->texture);
		i++;
	}
	return (0);
}

int	ft_load_textures_player(t_game *game)
{
	game->player->texture = mlx_load_png(PATH_PLAYER);
	game->player->texture1 = mlx_load_png(PATH_PLAYER1);
	game->player->texture2 = mlx_load_png(PATH_PLAYER2);
	if (!game->player->texture || !game->player->texture1
		|| !game->player->texture2)
		return (1);
	game->player->image = mlx_texture_to_image(game->game_window,
			game->player->texture);
	game->player->image1 = mlx_texture_to_image(game->game_window,
			game->player->texture1);
	game->player->image2 = mlx_texture_to_image(game->game_window,
			game->player->texture2);
	if (!game->player->image || !game->player->image1 || !game->player->image2)
		return (1);
	if (mlx_image_to_window(game->game_window, game->player->image,
			game->player->pos->x * PIXEL, game->player->pos->y * PIXEL) == -1)
		return (1);
	if (mlx_image_to_window(game->game_window, game->player->image1,
			game->player->pos->x * PIXEL, game->player->pos->y * PIXEL) == -1)
		return (1);
	if (mlx_image_to_window(game->game_window, game->player->image2,
			game->player->pos->x * PIXEL, game->player->pos->y * PIXEL) == -1)
		return (1);
	return (0);
}

int	ft_load_textures_enemy(t_game *game)
{
	game->enemy->texture = mlx_load_png(PATH_ENEMY);
	if (!game->enemy->texture)
		return (1);
	game->enemy->image = mlx_texture_to_image(game->game_window,
			game->enemy->texture);
	if (!game->enemy->image)
		return (1);
	if (mlx_image_to_window(game->game_window, game->enemy->image,
			game->enemy->pos->x * PIXEL, game->enemy->pos->y * PIXEL) == -1)
		return (1);
	return (0);
}

int	ft_load_textures_exit(t_game *game)
{
	game->exit->texture_closed = mlx_load_png(PATH_EXIT_CLOSED);
	if (!game->exit->texture_closed)
		return (call_exit(game), 0);
	game->exit->image_closed = mlx_texture_to_image(game->game_window,
			game->exit->texture_closed);
	if (!game->exit->image_closed)
		return (call_exit(game), 0);
	if (mlx_image_to_window(game->game_window, game->exit->image_closed,
			game->exit->pos->x * PIXEL, game->exit->pos->y * PIXEL) == -1)
		return (call_exit(game), 0);
	game->exit->texture_open = mlx_load_png(PATH_EXIT_OPEN);
	if (!game->exit->texture_open)
		return (call_exit(game), 0);
	game->exit->image_open = mlx_texture_to_image(game->game_window,
			game->exit->texture_open);
	if (!game->exit->image_open)
		return (call_exit(game), 0);
	if (mlx_image_to_window(game->game_window, game->exit->image_open,
			game->exit->pos->x * PIXEL, game->exit->pos->y * PIXEL) == -1)
		return (call_exit(game), 0);
	game->exit->image_open->instances->enabled = 0;
	return (0);
}
