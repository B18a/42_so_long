/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:51:44 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/22 17:09:56 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_item	**ft_initialize_item(t_game *game)
{
	t_item	**item;
	int		i;

	item = NULL;
	i = 0;
	item = malloc(game->item_total * sizeof(t_item*));
	while (i < game->item_total)
	{
		item[i] = malloc(1 * sizeof(t_item));
		item[i]->pos = NULL;
		i++;
	}
	return(item);
}

t_exit	*ft_initialize_exit()
{
	t_exit	*exit;

	exit = NULL;
	exit = ft_calloc(sizeof(t_exit), 1);
	if (exit)
	{
		exit->pos = NULL;
	}
	return (exit);
}

t_player	*ft_initialize_player()
{
	t_player	*player;

	player = NULL;
	player = ft_calloc(sizeof(t_player), 1);
	if (player)
	{
		player->pos = NULL;
		player->moves = 0;
		player->item = 0;
	}
	return (player);
}

mlx_t	*ft_init_window(t_game *game)
{
	game->map->width = ft_strlen(game->map->map_as_arr[0]) * PIXEL;
	game->map->height = get_height(game->map->map_as_arr) * PIXEL;
	game->game_window = mlx_init(game->map->width, game->map->height, NAME_WINDOW, true);
	if(!game->game_window)
		return (NULL);
	return(game->game_window);
}
