/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:09:33 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/01 23:50:31 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void check_leaks(void)
{
	system("leaks window");
}

void	ft_show_address(t_game *game)
{
	// printf("game		%p\n",(void*)&game);
	// printf("game.image	%p\n",(void*)&game->game_image);
	// printf("game.window	%p\n",(void*)&game->game_window);
	// printf("game.player		%p\n",(void*)&game->player);
	// printf("player.image	%p\n",(void*)&game->player->image);
	printf("player.texture	%p\n",(void*)&game->player->texture);
	// printf("player.pos		%p\n",(void*)&game->player->pos);

}




int	main(void)
{
	atexit(check_leaks);
	t_game	*game;
	const char *paths_assets[] = {PATHS};
	// const char *paths_assets[] = {PATH_PLAYER, PATH_ENEMY};


	game = NULL;
	game = ft_initialize_game();
	if (!ft_check_initialize(game))
		return (call_exit(game), 0);


	game->player->pos->x = 0;
	game->player->pos->y = 0;

	game->enemy->pos->x = 250;
	game->enemy->pos->y = 250;

	game->game_window = mlx_init(WIDTH, HEIGHT, NAME_WINDOW, false);
	// game->player->texture = mlx_load_png(PATH_PLAYER);
	// game->enemy->texture = mlx_load_png(PATH_ENEMY);

	// ft_load_textures(game, paths_assets);

	// game->player->image = mlx_texture_to_image(game->game_window, game->player->texture);
	// game->enemy->image = mlx_texture_to_image(game->game_window, game->enemy->texture);


	// if(!game->game_window || !game->player->texture || !game->player->image)
	// 	return (call_exit(game), 0);

	// ft_show_address(game);


	ft_load_textures(game, paths_assets);

	if(game)
	{



		// if(mlx_image_to_window(game->game_window, game->player->image, game->player->pos->x, game->player->pos->y) < 0)
		// 	return (call_exit(game), 0);

		// if(mlx_image_to_window(game->game_window, game->enemy->image, game->enemy->pos->x, game->enemy->pos->y) < 0)
		// 	return (call_exit(game), 0);

		mlx_key_hook(game->game_window, &my_keyhook, game);
		mlx_loop(game->game_window);
		mlx_terminate(game->game_window);
	}

	call_exit(game);

	return (0);
}
