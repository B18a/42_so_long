/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:09:33 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/08 16:28:19 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void check_leaks(void)
{
	system("leaks so_long");
}

void	ft_show_address(t_game *game)
{
	printf("game		%p\n",(void*)&game);
	printf("game.image	%p\n",(void*)&game->game_image);
	printf("game.window	%p\n",(void*)&game->game_window);
	printf("game->player->coordinates_x		%p\n",(void*)&game->player->coordinates_x);
	printf("game->player->coordinates_y		%p\n",(void*)&game->player->coordinates_y);
}

void start_game(t_game *game)
{
	if(game)
	{
		mlx_set_setting(MLX_STRETCH_IMAGE, 1);
		mlx_key_hook(game->game_window, &my_keyhook, game);
		mlx_loop(game->game_window);
		mlx_terminate(game->game_window);
	}
}


int	main(void)
{
	atexit(check_leaks);

	t_game	*game;
	const char *paths_enemy[] = {PATHS};

	game = NULL;
	game = ft_initialize_game();
	if (!ft_check_initialize(game))
		return (call_exit(game), 0);
	game->game_window = mlx_init(WIDTH, HEIGHT, NAME_WINDOW, true);
	if(!game->game_window)
		return (call_exit(game), 0);

	// ft_show_address(game);

	ft_load_textures_player(game);
	ft_load_textures_enemy(game, paths_enemy);


	// mlx_image_t *pos_player;
	// pos_player = mlx_put_string(game->game_window,"TEST", 200, 100);
	// mlx_delete_image(game->game_window, pos_player);

	start_game(game);

	call_exit(game);

	return (0);
}
