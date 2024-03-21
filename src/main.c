/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:09:33 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/21 12:29:55 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void check_leaks(void)
{
	system("leaks so_long");
}

void start_game(t_game *game)
{
	if(game)
	{
		mlx_set_setting(MLX_STRETCH_IMAGE, 1);
		mlx_key_hook(game->game_window, &my_keyhook, game);
		update_display_moves(game, 0, 100);
		update_display_item(game, 0, 100);
		mlx_loop(game->game_window);
		mlx_terminate(game->game_window);
	}
}

int	main(int argc, char**argv)
{
	atexit(check_leaks);

	t_game	*game;
	char	**map_as_arr;
	char	*map_as_string;

	game = NULL;
	map_as_arr = NULL;
	map_as_string = NULL;

	// const char *paths_enem[] = {PATHS_ENEMY};
	// const char *paths_item[] = {PATHS_ITEM};

	if(argc != 2)
	{
		printf("Input incorrect \n");
		return(0);
	}
	if(check_file_type(argv[1]))
	{
		printf("Filetype incorrect \n");
		return(0);
	}
	map_as_string = map_to_string(argv[1]);
	// printf("%s\n",map_as_string);
	if(map_char_check(map_as_string) > 0)
	{
		printf("map_char_check \n");
		call_exit_prep(map_as_string, map_as_arr);
		return(0);
	}
	map_as_arr = ft_split(map_as_string, '\n');

											// print_2d_arr(map_as_arr);

	if(map_arr_check(map_as_arr) > 0)
	{
		printf("map_arr_check \n");
		call_exit_prep(map_as_string, map_as_arr);
		return(0);
	}

	game = ft_initialize_game();
	if(!game)
	{
		call_exit_prep(map_as_string, map_as_arr);
		return(0);
	}
	game->map_as_arr = map_as_arr;
	game->map_as_string = map_as_string;


	ft_init_pos_asset(game, game->enemy , game->enemy_total);
	ft_init_pos_asset(game, game->item , game->item_total);
	/**************************************/

	game->width = ft_strlen(game->map_as_arr[0]) * PIXEL;
	game->height = get_height(game->map_as_arr) * PIXEL;


	t_pos	pos_player;
	pos_player = get_pos_player(game->map_as_arr);

	game->game_window = mlx_init(game->width, game->height, NAME_WINDOW, true);
	if(!game->game_window)
		return (call_exit(game), 0);

	// ft_show_address(game);

	ft_load_textures_floor(game, game->map_as_arr);
	ft_load_textures_obstacle(game, game->map_as_arr);
	ft_load_textures_player(game, pos_player.x * PIXEL, pos_player.y * PIXEL);
	// ft_load_textures_asset(game, game->enemy, paths_enem, game->enemy_total, (t_pos){100, 100});
	// ft_load_textures_asset(game, game->item, paths_item, game->item_total,(t_pos){300, 10});
	// ft_load_textures_exit(game, PATH_EXIT, (t_pos){0, 400});

	start_game(game);
	call_exit_prep(game->map_as_string, game->map_as_arr);
	call_exit(game);

	return (0);
}
