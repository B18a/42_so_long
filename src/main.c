/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:09:33 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/09 11:13:41 by ajehle           ###   ########.fr       */
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
}

void start_game(t_game *game)
{
	if(game)
	{
		mlx_set_setting(MLX_STRETCH_IMAGE, 1);
		mlx_key_hook(game->game_window, &my_keyhook, game);
		update_display_moves(game, 300, 100);
		update_display_item(game, 400, 100);
		mlx_loop(game->game_window);
		mlx_terminate(game->game_window);
	}
}


int	main(void)
{
	atexit(check_leaks);

	t_game	*game;
	const char *paths_enem[] = {PATHS_ENEMY};
	const char *paths_item[] = {PATHS_ITEM};

	game = NULL;
	game = ft_initialize_game();
	if(!game)
		return(0);




	ft_init_pos_asset(game, game->enemy , game->enemy_total);
	ft_init_pos_asset(game, game->item , game->item_total);
	/**************************************/
	/**************************************/
	game->game_window = mlx_init(WIDTH, HEIGHT, NAME_WINDOW, true);
	if(!game->game_window)
		return (call_exit(game), 0);

	// ft_show_address(game);


	if(ft_load_textures_exit(game, PATH_EXIT, (t_pos){0, 400}))
		call_exit(game);
	ft_load_textures_player(game, 0, 0);
	if(ft_load_textures_asset(game, game->enemy, paths_enem, game->enemy_total, (t_pos){100, 100}))
		call_exit(game);
	if(ft_load_textures_asset(game, game->item, paths_item, game->item_total,(t_pos){0, 10}))
		call_exit(game);


	// mlx_image_t *pos_player;
	// pos_player = mlx_put_string(game->game_window,"TEST", 200, 100);
	// mlx_delete_image(game->game_window, pos_player);

	start_game(game);

	call_exit(game);

	return (0);
}
