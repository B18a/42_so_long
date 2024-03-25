/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:09:33 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/25 08:56:32 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_leaks(void)
{
	system("leaks so_long");
}

void	start_game(t_game *game)
{
	if (game)
	{
		mlx_set_setting(MLX_STRETCH_IMAGE, 1);
		mlx_key_hook(game->game_window, &my_keyhook, game);
		mlx_loop(game->game_window);
		mlx_terminate(game->game_window);
	}
}

t_map	*parsing_input(char *map_input)
{
	t_map	*map;

	map = NULL;
	map = ft_calloc(sizeof(t_map), 1);
	if (!map)
		return (NULL);
	if (check_file_type(map_input))
		return (ft_printf("Filetype incorrect \n"), call_exit_map(map), NULL);
	map->map_as_string = map_to_string(map_input);
	if (!map->map_as_string)
		return (call_exit_map(map), NULL);
	if (map_string_check(map->map_as_string) > 0)
		return (ft_printf("map_string_check \n"), call_exit_map(map), NULL);
	map->map_as_arr = ft_split(map->map_as_string, '\n');
	if (!(map->map_as_arr))
		return (map);
	if (map_arr_check(map->map_as_arr) > 0)
		return (ft_printf("map_arr_check \n"), call_exit_map(map), NULL);
	return (map);
}

void	load_textures(t_game *game)
{
	ft_load_textures_floor(game, game->map->map_as_arr);
	ft_load_textures_obstacle(game, game->map->map_as_arr);
	ft_load_textures_exit(game);
	ft_load_textures_item(game);
	ft_load_textures_player(game);
	update_display_moves(game, MOVES_POS_X, MOVES_POS_Y);
	update_display_item(game, ITEM_POS_X, ITEM_POS_Y);
}

int	main(int argc, char **argv)
{
	t_map	*map;
	t_game	*game;

	atexit(check_leaks);
	map = NULL;
	game = NULL;
	if (argc != 2)
	{
		printf("Input incorrect \n");
		return (0);
	}
	map = parsing_input(argv[1]);
	if (!map)
		return (call_exit_map(map), 0);
	game = ft_initialize(map);
	if (!game)
		return (call_exit(game), 0);
	load_textures(game);
	start_game(game);
	call_exit(game);
	return (0);
}
