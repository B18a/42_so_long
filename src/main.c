/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:09:33 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/08 12:20:24 by ajehle           ###   ########.fr       */
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
	// printf("asset[0].texture	%p\n",(void*)&game->assets[0]->texture);
	// printf("asset[0].image		%p\n",(void*)&game->assets[0]->image);
	// printf("asset[0].pos		%p\n",(void*)&game->assets[0]->pos);
	// printf("asset[1].texture	%p\n",(void*)&game->assets[1]->texture);
	// printf("asset[1].image	%p\n",(void*)&game->assets[1]->image);
	// printf("asset[1].pos		%p\n",(void*)&game->assets[1]->pos);
	// printf("asset				%p\n",(void*)&game->assets);

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
	game->game_window = mlx_init(WIDTH, HEIGHT, NAME_WINDOW, true);
	if(!game->game_window)
		return (call_exit(game), 0);

	// ft_show_address(game);

	ft_load_textures_player(game);
	ft_load_textures_assets(game, paths_assets);


	mlx_image_t *pos_player;
	pos_player = mlx_put_string(game->game_window,"TEST", 200, 100);
	mlx_delete_image(game->game_window, pos_player);

	if(game)
	{
		mlx_set_setting(MLX_STRETCH_IMAGE, 1);
		mlx_key_hook(game->game_window, &my_keyhook, game);
		mlx_loop(game->game_window);
		mlx_terminate(game->game_window);
	}
	call_exit(game);

	return (0);
}
