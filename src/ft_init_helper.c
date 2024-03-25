/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:51:44 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/25 12:05:49 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_game	*ft_initialize_game(t_map *map)
{
	t_game	*game;

	game = NULL;
	game = ft_calloc(sizeof(t_game), 1);
	if (!game)
		return (NULL);
	game->map = map;
	game->game_window = NULL;
	game->game_image = NULL;
	game->item = NULL;
	game->item_collect = 0;
	game->item_image = NULL;
	return (game);
}

t_exit	*ft_initialize_exit(void)
{
	t_exit	*exit;

	exit = NULL;
	exit = ft_calloc(sizeof(t_exit), 1);
	if (!exit)
		return (NULL);
	if (exit)
	{
		exit->texture_closed = NULL;
		exit->image_closed = NULL;
		exit->texture_open = NULL;
		exit->image_open = NULL;
		exit->pos = NULL;
	}
	return (exit);
}

t_player	*ft_initialize_player(void)
{
	t_player	*player;

	player = NULL;
	player = ft_calloc(sizeof(t_player), 1);
	if (player)
	{
		player->pos = NULL;
		player->texture = NULL;
		player->image = NULL;
		player->moves = 0;
	}
	return (player);
}

mlx_t	*ft_init_window(t_game *game)
{
	game->map->width = ft_strlen(game->map->map_as_arr[0]) * PIXEL;
	game->map->height = get_height(game->map->map_as_arr) * PIXEL;
	game->game_window = mlx_init(game->map->width, game->map->height,
			NAME_WINDOW, true);
	if (!game->game_window)
		return (NULL);
	return (game->game_window);
}
