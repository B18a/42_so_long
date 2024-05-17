/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:51:44 by ajehle            #+#    #+#             */
/*   Updated: 2024/04/19 13:59:34 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	start_player(t_game *game, t_map *map)
{
	game->player = ft_initialize_player();
	if (!game->player)
		return (1);
	game->player->pos = get_pos_unique(map->map_as_arr, 'P');
	if (!game->player->pos)
		return (1);
	return (0);
}

static int	start_exit(t_game *game, t_map *map)
{
	game->exit = ft_initialize_exit();
	if (!game->exit)
		return (1);
	game->exit->pos = get_pos_unique(map->map_as_arr, 'E');
	if (!game->exit->pos)
		return (1);
	return (0);
}

static int	start_item(t_game *game)
{
	game->item = ft_initialize_item(game);
	if (!game->item)
		return (1);
	if (init_pos_items(game) == 0)
		return (1);
	return (0);
}

static int	start_enemy(t_game *game, t_map *map)
{
	game->enemy = ft_initialize_enemy();
	if (!game->enemy)
		return (1);
	if (get_enemy_pos(game, map))
		return (1);
	return (0);
}

t_game	*ft_initialize(t_map *map)
{
	t_game	*game;

	game = ft_initialize_game(map);
	if (!game)
		return (NULL);
	if (start_player(game, map))
		return (ft_printf("Error\n"), call_exit(game), NULL);
	if (start_exit(game, map))
		return (ft_printf("Error\n"), call_exit(game), NULL);
	if (start_item(game))
		return (ft_printf("Error\n"), call_exit(game), NULL);
	if (start_enemy(game, map))
		return (ft_printf("Error\n"), call_exit(game), NULL);
	if (!ft_init_window(game))
		return (ft_printf("Error\n"), call_exit(game), NULL);
	return (game);
}
