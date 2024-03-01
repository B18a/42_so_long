/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:51:44 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/01 20:01:31 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_hook(void *param)
{
	t_game *game;

	game = param;
	if (mlx_is_key_down(game->game_window, MLX_KEY_ESCAPE))
		mlx_close_window(game->game_window);

}
void my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game *game;

	game = param;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
	{
		game->player->pos->y -= 5;
		mlx_image_to_window(game->game_window, game->player->image, game->player->pos->x, game->player->pos->y);
	}
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
	{
		game->player->pos->y += 5;
		mlx_image_to_window(game->game_window, game->player->image, game->player->pos->x, game->player->pos->y);
	}
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
	{
		game->player->pos->x -= 5;
		mlx_image_to_window(game->game_window, game->player->image, game->player->pos->x, game->player->pos->y);
	}
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
	{
		game->player->pos->x += 5;
		mlx_image_to_window(game->game_window, game->player->image, game->player->pos->x, game->player->pos->y);
	}
}
