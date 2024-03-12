/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreasjehle <andreasjehle@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:09:33 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/12 21:35:42 by andreasjehl      ###   ########.fr       */
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

void 	print_2d_arr(char **map_in_arr)
{
	int i = 0;
	int j = 0;
	while(map_in_arr[i])
	{
		printf("[%i]\n",i);
		while(map_in_arr[i][j])
		{
			printf("%c",map_in_arr[i][j]);
			j++;
		}
		j = 0;
		i++;
	}
}


int	main(int argc, char**argv)
{
	// atexit(check_leaks);

	char	**map_in_arr;


	// t_game	*game;
	// const char *paths_enem[] = {PATHS_ENEMY};
	// const char *paths_item[] = {PATHS_ITEM};

	if(argc != 2)
	{
		printf("Input incorrect \n");
		return(0);
	}

	
	map_in_arr = parse_input(argv[1]);
	print_2d_arr(map_in_arr);
									// free map in arr is missing!!!
	// game = NULL;
	// game = ft_initialize_game();
	// if(!game)
	// 	return(0);



	// ft_init_pos_asset(game, game->enemy , game->enemy_total);
	// ft_init_pos_asset(game, game->item , game->item_total);
	// /**************************************/

	// game->game_window = mlx_init(WIDTH, HEIGHT, NAME_WINDOW, true);
	// if(!game->game_window)
	// 	return (call_exit(game), 0);

	// // ft_show_address(game);


	// ft_load_textures_player(game, 0, 0);
	// // ft_load_textures_asset(game, game->enemy, paths_enem, game->enemy_total, (t_pos){100, 100});
	// // ft_load_textures_asset(game, game->item, paths_item, game->item_total,(t_pos){300, 10});
	// // ft_load_textures_exit(game, PATH_EXIT, (t_pos){0, 400});


	// // start_game(game);
	// call_exit(game);

	return (0);
}
