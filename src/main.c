/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:09:33 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/02 11:14:43 by ajehle           ###   ########.fr       */
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
	// printf("asset[0].texture	%p\n",(void*)&game->assets[0]->texture);
	// printf("asset[0].image		%p\n",(void*)&game->assets[0]->image);
	// printf("asset[0].pos		%p\n",(void*)&game->assets[0]->pos);
	// printf("asset[1].texture	%p\n",(void*)&game->assets[1]->texture);
	// printf("asset[1].image	%p\n",(void*)&game->assets[1]->image);
	// printf("asset[1].pos		%p\n",(void*)&game->assets[1]->pos);
	printf("asset				%p\n",(void*)&game->assets);

}

int	ft_textures_analogway(t_game *game)
{
	game->player->pos->x = 0;
	game->player->pos->y = 0;

	game->enemy->pos->x = 250;
	game->enemy->pos->y = 250;

	game->player->texture = mlx_load_png(PATH_PLAYER);
	game->enemy->texture = mlx_load_png(PATH_ENEMY);

	game->player->image = mlx_texture_to_image(game->game_window, game->player->texture);
	game->enemy->image = mlx_texture_to_image(game->game_window, game->enemy->texture);


	if(mlx_image_to_window(game->game_window, game->player->image, game->player->pos->x, game->player->pos->y) < 0)
		return (call_exit(game), 0);

	if(mlx_image_to_window(game->game_window, game->enemy->image, game->enemy->pos->x, game->enemy->pos->y) < 0)
		return (call_exit(game), 0);
	return(1);
}


int	main(void)
{
	atexit(check_leaks);
	t_game	*game;
	const char *paths_assets[] = {PATHS};


	game = NULL;
	game = ft_initialize_game();
	if (!ft_check_initialize(game))
		return (call_exit(game), 0);
	game->game_window = mlx_init(WIDTH, HEIGHT, NAME_WINDOW, false);


	// ft_load_(game, paths_assets);

	// if(!game->game_window || !game->player->texture || !game->player->image)
	// 	return (call_exit(game), 0);

	ft_show_address(game);

	// ft_textures_analogway(game);
	ft_load_textures(game, paths_assets);

	if(game)
	{
		mlx_key_hook(game->game_window, &my_keyhook, game);
		mlx_loop(game->game_window);
		mlx_terminate(game->game_window);
	}

	call_exit(game);

	return (0);
}
