/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:51:44 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/22 15:27:58 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_game	*ft_initialize_game(t_map *map)
{
	t_game	*game;

	game = NULL;
	game = ft_calloc(sizeof(t_game), 1);
	if(!game)
		return(NULL);
	game->map = map;
	game->game_window = NULL;
	game->game_image = NULL;

// /*******PLAYER*************************************************/
	game->player = ft_initialize_player();
	if(!game->player)
		return(NULL);
	game->player->pos = get_pos_unique(map->map_as_arr, 'P');
	if(!game->player->pos)
		return(NULL);

// /*******EXIT***************************************************/
	game->exit = ft_initialize_exit();
	if(!game->exit)
		return(NULL);
	game->exit->pos = get_pos_unique(map->map_as_arr, 'E');
	if(!game->exit->pos)
		return(NULL);

// /*******ITEM***************************************************/
	// game->item_total = get_item_total(map->map_as_string);
	// printf("items total %i\n", game->item_total);
	// game->item = ft_initialize_item(game->item_total);
	// game->item->pos = get_pos_unique(map->map_as_arr, 'C');


/*********ENEMY*************************************************/

// /**************************************************************/
	if(!ft_init_window(game))
		return(NULL);

	return (game);
}
