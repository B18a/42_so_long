/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:51:44 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/25 15:59:23 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_game	*ft_initialize(t_map *map)
{
	t_game	*game;

	game = ft_initialize_game(map);
	if (!game)
		return (NULL);
	game->player = ft_initialize_player();
	if (!game->player)
		return (call_exit(game), NULL);
	game->player->pos = get_pos_unique(map->map_as_arr, 'P');
	if (!game->player->pos)
		return (call_exit(game), NULL);
	game->exit = ft_initialize_exit();
	if (!game->exit)
		return (call_exit(game), NULL);
	game->exit->pos = get_pos_unique(map->map_as_arr, 'E');
	if (!game->exit->pos)
		return (call_exit(game), NULL);
	game->item_total = get_item_total(map->map_as_string);
	game->item = ft_initialize_item(game);
	if (!game->item)
		return (call_exit(game), NULL);
	if (ft_init_pos_items(game) == 0)
		return (call_exit(game), NULL);
	if (!ft_init_window(game))
		return (call_exit(game), NULL);
	return (game);
}
