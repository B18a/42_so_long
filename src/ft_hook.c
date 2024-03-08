/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:51:44 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/08 12:43:15 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// void	my_keyhook(mlx_key_data_t keydata, void *param)
// {
// 	t_game	*game;

// 	game = param;
// 	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
// 		mlx_close_window(game->game_window);
// 	// if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS) // One Step per Press
// 	if (keydata.key == MLX_KEY_UP)
// 	{
// 		if (game->assets[0]->image->instances[0].y - 10 >= 0)
// 			game->assets[0]->image->instances[0].y -= 10;
// 	}
// 	// if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
// 	if (keydata.key == MLX_KEY_DOWN)
// 	{
// 		if (game->assets[0]->image->instances[0].y + 10 <= 450)
// 			game->assets[0]->image->instances[0].y += 10;
// 	}
// 	// if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
// 	if (keydata.key == MLX_KEY_LEFT)
// 	{
// 		if( game->assets[0]->image->instances[0].x - 10 >= 0)
// 			game->assets[0]->image->instances[0].x -= 10;
// 	}
// 	// if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
// 	if (keydata.key == MLX_KEY_RIGHT)
// 	{
// 		if (game->assets[0]->image->instances[0].x + 10 <= 450)
// 			game->assets[0]->image->instances[0].x += 10;
// 	}
// }

void	ft_show_pos(t_game * game)
{
	char *string;

	// string = NULL;
	string = ft_itoa(game->player->pos->x);
	printf("String is %s", string);
	game->player->coordinates = mlx_put_string(game->game_window,string,200,100);
	if(string)
		free(string);

}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_delete_image(game->game_window,game->player->coordinates);
		mlx_close_window(game->game_window);
	}
	// if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS) // One Step per Press
	if (keydata.key == MLX_KEY_UP)
	{
		if (game->player->image->instances[0].y - 10 >= 0)
			game->player->image->instances[0].y -= 10;
	}
	// if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
	if (keydata.key == MLX_KEY_DOWN)
	{
		// ft_show_pos(game);
		if (game->player->image->instances[0].y + 10 <= 450)
			game->player->image->instances[0].y += 10;
	}
	// if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
	if (keydata.key == MLX_KEY_LEFT)
	{
		if( game->player->image->instances[0].x - 10 >= 0)
			game->player->image->instances[0].x -= 10;
	}
	// if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
	if (keydata.key == MLX_KEY_RIGHT)
	{
		if (game->player->image->instances[0].x + 10 <= 450)
			game->player->image->instances[0].x += 10;
	}
}
