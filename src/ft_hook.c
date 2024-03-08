/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:51:44 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/08 15:42:58 by ajehle           ###   ########.fr       */
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

// static void	ft_show_pos_player(t_game *game)
// {
// 	char *string_x;
// 	char *string_y;
// 	char *string_width;
// 	char *string_height;

// 	string_x = ft_itoa(game->player->image->instances[0].x);
// 	string_y = ft_itoa(game->player->image->instances[0].y);
// 	string_width = ft_itoa(game->player->image->width);
// 	string_height = ft_itoa(game->player->image->height);
// 	mlx_delete_image(game->game_window, game->player->coordinates_x);
// 	mlx_delete_image(game->game_window, game->player->coordinates_y);
// 	mlx_delete_image(game->game_window, game->player->width);
// 	mlx_delete_image(game->game_window, game->player->height);
// 	game->player->coordinates_x = mlx_put_string(game->game_window,string_x,100,0);
// 	game->player->coordinates_y = mlx_put_string(game->game_window,string_y,200,0);
// 	game->player->width = mlx_put_string(game->game_window,string_width,300,0);
// 	game->player->height = mlx_put_string(game->game_window,string_height,400,0);
// 	if(string_x)
// 		free(string_x);
// 	if(string_y)
// 		free(string_y);
// 	if(string_width)
// 		free(string_width);
// 	if(string_height)
// 		free(string_height);
// }

void check_collision(t_game *game)
{
	int aminX;
	int amaxX;
	int aminY;
	int amaxY;
	int bminX;
	int bmaxX;
	int bminY;
	int bmaxY;
	int i;

	i = 0;
	aminX = game->player->image->instances[0].x;
	amaxX = game->player->image->instances[0].x + game->player->image->width;
	aminY = game->player->image->instances[0].y;
	amaxY = game->player->image->instances[0].y + game->player->image->height;

	while(i < AMOUNT_ASSETS)
	{
		bminX = game->assets[i]->image->instances[0].x;
		bmaxX = game->assets[i]->image->instances[0].x + game->assets[0]->image->width;
		bminY = game->assets[i]->image->instances[0].y;
		bmaxY = game->assets[i]->image->instances[0].y + game->assets[0]->image->height;

		if((amaxX >= bminX) && (aminX <= bmaxX) && (amaxY >= bminY) && (aminY <= bmaxY))
			printf("Collision\n");
		else
			printf("OK\n");
		i++;
	}
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
	// if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS) // One Step per Press
	if (keydata.key == MLX_KEY_UP)
	{
		if (game->player->image->instances[0].y - PLAYER_STEP >= 0)
			game->player->image->instances[0].y -= PLAYER_STEP;
	}
	// if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
	if (keydata.key == MLX_KEY_DOWN)
	{
		// if (game->player->image->instances[0].y + PLAYER_STEP <= (HEIGHT - game->player->image->height))
		if (game->player->image->instances[0].y + PLAYER_STEP <= 450)
			game->player->image->instances[0].y += PLAYER_STEP;
	}
	// if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
	if (keydata.key == MLX_KEY_LEFT)
	{
		if( game->player->image->instances[0].x - PLAYER_STEP >= 0)
			game->player->image->instances[0].x -= PLAYER_STEP;
	}
	// if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
	if (keydata.key == MLX_KEY_RIGHT)
	{
		// if (game->player->image->instances[0].x + PLAYER_STEP <= (WIDTH - game->player->image->width))
		if (game->player->image->instances[0].x + PLAYER_STEP <= 450)
			game->player->image->instances[0].x += PLAYER_STEP;
	}
	check_collision(game);
}
