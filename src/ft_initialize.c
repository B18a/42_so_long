/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:51:44 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/22 12:45:50 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_asset	**ft_initialize_asset(int amount)
{
	int		i;
	int		j;
	t_asset	**asset;

	i = 0;
	j = 0;
	asset = ft_calloc(sizeof(t_asset*) , amount);
	if (asset)
	{
		while (i < amount)
		{
			asset[i] = ft_calloc(sizeof(t_asset), 1);
			if (!asset[i])
			{
				while (j < i)
				{
					if (asset[j])
						free(asset[j]);
					j++;
				}
				if (asset)
					free(asset);
				return (NULL);
			}
			i++;
		}
	}
	return (asset);
}


t_pos	*ft_initialize_pos(void)
{
	t_pos	*pos;

	pos = NULL;
	pos = ft_calloc(sizeof(t_pos), 1);
	if(!pos)
		return(NULL);
	pos->y = 0;
	pos->x = 0;
	return (pos);
}

void ft_init_pos_asset(t_game *game, t_asset **asset, int amount)
{
	int	i;

	i = 0;
	if (asset)
	{
		while (i < amount)
		{
			asset[i]->pos = NULL;
			asset[i]->pos = ft_initialize_pos();
			if (!asset[i]->pos)
				call_exit(game);
			i++;
		}
	}
}



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
int	get_item_total(char *map_as_string)
{
	int i;
	int item;

	i = 0;
	item = 0;
	while(map_as_string[i])
	{
		if(map_as_string[i] == 'C')
			item++;
		i++;
	}
	return(item);
}

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
	printf("exit [%i][%i]\n", game->exit->pos->y, game->exit->pos->x);
	if(!game->exit->pos)
		return(NULL);

// /*******ITEM***************************************************/
	game->item_total = get_item_total(map->map_as_string);
	printf("items total %i\n", game->item_total);


/**************************************************************/
		// game->item_total = AMOUNT_ITEM;
		// game->enemy_total = AMOUNT_ENEMY;

// /**************************************************************/
// 		game->enemy = NULL;
// 		game->enemy = ft_initialize_asset(game->enemy_total);
// 		// return value must be checked?
// 		// ft_init_pos_asset(game, game->enemy , game->enemy_total); // switched to main because position needs to be read from input
// /**************************************************************/
// 		game->item = NULL;
// 		game->item = ft_initialize_asset(game->item_total);
// 		// game->item_begin = ft_initialize_item(game, game->item_total);
// 		// return value must be checked?
// 		// ft_init_pos_asset(game, game->item , game->item_total); // switched to main because position needs to be read from input
// /**************************************************************/
	if(!ft_init_window(game))
		return(NULL);

	return (game);
}
