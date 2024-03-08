/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:51:44 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/08 20:34:40 by ajehle           ###   ########.fr       */
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
	while(i < AMOUNT_ENEMY)
	{
		bminX = game->enemy[i]->image->instances[0].x;
		bmaxX = game->enemy[i]->image->instances[0].x + game->enemy[0]->image->width;
		bminY = game->enemy[i]->image->instances[0].y;
		bmaxY = game->enemy[i]->image->instances[0].y + game->enemy[0]->image->height;
		if((amaxX >= bminX) && (aminX <= bmaxX) && (amaxY >= bminY) && (aminY <= bmaxY))
			mlx_close_window(game->game_window);
		i++;
	}
}

void	update_display_moves(t_game *game)
{
	char *str_moves;

	str_moves = ft_itoa(game->player->moves);
	mlx_delete_image(game->game_window, game->player->move_image);
	game->player->move_image = mlx_put_string(game->game_window,str_moves, 400, 100);
	if(str_moves)
		free(str_moves);

	char *string_x;

	string_x = ft_itoa(game->player->image->instances[0].x);
	mlx_delete_image(game->game_window, game->player->coordinates_x);
	game->player->coordinates_x = mlx_put_string(game->game_window,string_x,100,0);
	if(string_x)
		free(string_x);
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if(keydata.action == MLX_PRESS)
		game->player->moves += 1;
	update_display_moves(game);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		// delete_temp_images(game);
		mlx_close_window(game->game_window);
	}
	// if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS) // One Step per Press
	if (keydata.key == MLX_KEY_W)
	{
		if (game->player->image->instances[0].y - PLAYER_STEP >= 0)
			game->player->image->instances[0].y -= PLAYER_STEP;
	}
	// if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
	if (keydata.key == MLX_KEY_S)
	{
		if (game->player->image->instances[0].y + PLAYER_STEP <= (int)(HEIGHT - game->player->image->height))
			game->player->image->instances[0].y += PLAYER_STEP;
	}
	// if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
	if (keydata.key == MLX_KEY_A)
	{
		if( game->player->image->instances[0].x - PLAYER_STEP >= 0)
			game->player->image->instances[0].x -= PLAYER_STEP;
	}
	// if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
	if (keydata.key == MLX_KEY_D)
	{
		if (game->player->image->instances[0].x + PLAYER_STEP <= (int)(WIDTH - game->player->image->width))
			game->player->image->instances[0].x += PLAYER_STEP;
	}
	check_collision(game);
}
