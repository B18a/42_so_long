/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:09:33 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/01 14:27:24 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void check_leaks(void)
{
	system("leaks window");
}

void	ft_show_address(t_game *game)
{
	printf("game		%p\n",(void*)&game);
	printf("game.image	%p\n",(void*)&game->game_image);
	printf("game.window	%p\n",(void*)&game->game_window);
	// printf("game.player		%p\n",(void*)&game->player);
	// printf("player.image	%p\n",(void*)&game->player->image);
	// printf("player.texture	%p\n",(void*)&game->player->texture);
	// printf("player.pos		%p\n",(void*)&game->player->pos);

}

int	main(void)
{
	atexit(check_leaks);
	t_game	*game;

	game = NULL;
	game = ft_initialize_game();
	// if (!game)
	// 	return (ft_exit_game(game), 0);
	// game->player = ft_initialize_player();
	// if (!game->player)
	// 	return (call_exit(game), 0);
	// game->player->texture = mlx_load_png("./assets/Link.png");
	// game->player->image = mlx_texture_to_image(game->game_window, game->player->texture);

	ft_show_address(game);
	// mlx_image_to_window(game->game_window, game->player->image, game->player->pos->x, game->player->pos->y);
	mlx_loop_hook(game->game_window, ft_hook, game);
	mlx_loop(game->game_window);
	mlx_terminate(game->game_window);

	call_exit(game);


	return (0);
}