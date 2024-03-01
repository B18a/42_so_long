/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:51:44 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/01 14:27:44 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"


t_pos	*ft_initialize_pos(void)
{
	t_pos	*pos;
	pos = NULL;
	pos = malloc(sizeof(t_pos));
	pos->x = 300;
	pos->y = 300;
	return(pos);
}


t_player	*ft_initialize_player(void)
{
	t_player	*player;

	player = NULL;
	player = malloc(sizeof(t_player));
	player->pos = NULL;
	player->pos = ft_initialize_pos();
	if(!player->pos)
		return (NULL);
	return (player);
}

t_game	*ft_initialize_game(void)
{
	t_game	*game;

	game = NULL;
	game = malloc(sizeof(t_game));
	// if (!game)
	// 	return (ft_exit_game(game), NULL);
	// game->game_window = malloc(sizeof(mlx_t));
	// if (!game->game_window)
	// 	return (ft_exit_game(game), NULL);
	game->game_window = mlx_init(WIDTH, HEIGHT, "test", false);
	// if (!game->game_window)
	// 	return (call_exit(game), NULL);
	// game->game_image = malloc(sizeof(mlx_image_t));
	// if (!game->game_image)
	// 	return (ft_exit_game(game), NULL);
	// game->game_image = mlx_new_image(game->game_window, WIDTH, HEIGHT);
	// if (!game->game_image)
	// 	return (call_exit(game), NULL);
	// if (mlx_image_to_window(game->game_window, game->game_image, 100, 0) == -1)
	// 	return (call_exit(game), NULL);
	// game->player = malloc(sizeof(t_player));
	// if (!game->player)
	// 	return (ft_exit_game(game), NULL);
	return (game);
}
