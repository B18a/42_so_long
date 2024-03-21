/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:09:33 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/21 09:22:57 by ajehle           ###   ########.fr       */
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
	printf("	[0][1][2][3][4][5][7][8][9]\n");
	while(map_in_arr[i])
	{
		printf("[%i]	",i);
		while(map_in_arr[i][j])
		{
			printf(" %c ",map_in_arr[i][j]);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
}


char	*read_map(char *map)
{
	char	*line;
	char	*line_joined;
	int		fd;

	fd = open(map, O_RDONLY);
	line_joined = ft_calloc(1, 1);
	if (!line_joined)
		return (NULL);
	while (1)
	{
		line = get_next_line (fd);
		if (line)
		{
			line_joined = ft_strjoin(line_joined, line);
			free(line);
		}
		else
			break ;
	}
	close (fd);
	return (line_joined);
}

int	check_file_type(char *str)
{
	while(str && *str != '.')
		str++;
	// printf("%s\n",str);
	if(ft_strncmp(str,".ber",4))
		return(1);
	return(0);
}

void	call_exit_prep(char *map_as_string, char **map_as_arr)
{
	int i;

	i = 0;
	if(map_as_string)
		free(map_as_string);
	if(map_as_arr)
	{
	while(map_as_arr[i])
	{
		free(map_as_arr[i]);
		i++;
	}
	free(map_as_arr);
	}
}

int	main(int argc, char**argv)
{
	atexit(check_leaks);

	char	**map_as_arr;
	char	*map_as_string;

	map_as_arr = NULL;
	t_game	*game;
	const char *paths_enem[] = {PATHS_ENEMY};
	const char *paths_item[] = {PATHS_ITEM};

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

	game = NULL;
	game = ft_initialize_game();
	if(!game)
	{
		call_exit_prep(map_as_string, map_as_arr);
		return(0);
	}



	ft_init_pos_asset(game, game->enemy , game->enemy_total);
	ft_init_pos_asset(game, game->item , game->item_total);
	/**************************************/

	game->game_window = mlx_init(WIDTH, HEIGHT, NAME_WINDOW, true);
	if(!game->game_window)
		return (call_exit(game), 0);

	// ft_show_address(game);


	ft_load_textures_player(game, 0, 0);
	ft_load_textures_asset(game, game->enemy, paths_enem, game->enemy_total, (t_pos){100, 100});
	ft_load_textures_asset(game, game->item, paths_item, game->item_total,(t_pos){300, 10});
	ft_load_textures_exit(game, PATH_EXIT, (t_pos){0, 400});


	start_game(game);
	call_exit_prep(map_as_string, map_as_arr);
	call_exit(game);

	return (0);
}
