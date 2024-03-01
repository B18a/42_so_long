/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:09:33 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/01 09:55:14 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"


int	main(void)
{

/************************************************/
/****************Initialize Game**************/
/************************************************/
	t_game	*game;

	game = ft_initialize_game();
	if (!game)
		return(ft_exit_game(game), 0);

/************************************************/
/****************Initialize Player**************/
/************************************************/
	game->player = ft_initialize_player();
	if(!game->player)
		return(call_exit(game), 0);

/************************************************/
/****************Draw Line**************/
/************************************************/
	int x;
	x = 0;
	while (x < 300)
	{
		x++;
		mlx_put_pixel(game->game_image, x, 100, 0xFF00F0FF);
	}

/************************************************/
/****************Load and Draw Player************/
/************************************************/
	game->player->texture = mlx_load_png("./assets/Link.png");
	game->player->image = mlx_texture_to_image(game->game_window, game->player->texture);

	mlx_image_to_window(game->game_window, game->player->image, game->player->x_pos_player, game->player->y_pos_player);
	//*******************************************************

	mlx_loop_hook(game->game_window, ft_hook, game->game_window);
	// mlx_loop_hook(game->game_window, ft_hook_movement, game->player);

	mlx_loop(game->game_window);

	return (0);
}