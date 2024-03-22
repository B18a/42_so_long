/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:51:44 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/22 15:27:56 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_exit *ft_initialize_exit()
{
	t_exit	*exit;

	exit = NULL;
	exit = ft_calloc(sizeof(t_asset), 1);
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
// t_asset	**ft_initialize_asset(int amount)
// {
// 	int		i;
// 	int		j;
// 	t_asset	**asset;

// 	i = 0;
// 	j = 0;
// 	asset = ft_calloc(sizeof(t_asset*) , amount);
// 	if (asset)
// 	{
// 		while (i < amount)
// 		{
// 			asset[i] = ft_calloc(sizeof(t_asset), 1);
// 			if (!asset[i])
// 			{
// 				while (j < i)
// 				{
// 					if (asset[j])
// 						free(asset[j]);
// 					j++;
// 				}
// 				if (asset)
// 					free(asset);
// 				return (NULL);
// 			}
// 			i++;
// 		}
// 	}
// 	return (asset);
// }


// t_pos	*ft_initialize_pos(void)
// {
// 	t_pos	*pos;

// 	pos = NULL;
// 	pos = ft_calloc(sizeof(t_pos), 1);
// 	if(!pos)
// 		return(NULL);
// 	pos->y = 0;
// 	pos->x = 0;
// 	return (pos);
// }

// void ft_init_pos_asset(t_game *game, t_asset **asset, int amount)
// {
// 	int	i;

// 	i = 0;
// 	if (asset)
// 	{
// 		while (i < amount)
// 		{
// 			asset[i]->pos = NULL;
// 			asset[i]->pos = ft_initialize_pos();
// 			if (!asset[i]->pos)
// 				call_exit(game);
// 			i++;
// 		}
// 	}
// }
