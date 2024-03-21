/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:51:44 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/21 15:32:12 by ajehle           ###   ########.fr       */
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

t_player	*ft_initialize_player(void)
{
	t_player	*player;

	player = ft_calloc(sizeof(t_player), 1);
	if (player)
			{
				player->pos = NULL;
				player->pos = ft_initialize_pos();
				player->moves = 0;
				player->item = 0;
			}
	return (player);
}

t_pos	*ft_initialize_pos(void)
{
	t_pos	*pos;

	pos = NULL;
	pos = ft_calloc(sizeof(t_pos), 1);
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

t_asset *ft_initialize_exit(void)
{
	t_asset	*exit;

	exit = ft_calloc(sizeof(t_asset), 1);
	if (exit)
	{
		exit->pos = NULL;
		exit->pos = ft_initialize_pos();
	}
	return (exit);
}


t_game	*ft_initialize_game(void)
{
	t_game	*game;

	game = NULL;
	game = ft_calloc(sizeof(t_game), 1);
	if (game)
	{

		game->item_total = AMOUNT_ITEM;
		game->enemy_total = AMOUNT_ENEMY;
/**************************************************************/
		game->player = NULL;
		game->player = ft_initialize_player();

/**************************************************************/
		game->enemy = NULL;
		game->enemy = ft_initialize_asset(game->enemy_total);
		// return value must be checked?
		// ft_init_pos_asset(game, game->enemy , game->enemy_total); // switched to main because position needs to be read from input
/**************************************************************/
		game->item = NULL;
		game->item = ft_initialize_asset(game->item_total);
		// game->item_begin = ft_initialize_item(game, game->item_total);
		// return value must be checked?
		// ft_init_pos_asset(game, game->item , game->item_total); // switched to main because position needs to be read from input
/**************************************************************/
		game->exit = NULL;
		game->exit = ft_initialize_exit();
/**************************************************************/
		game->game_window = NULL;
		game->game_image = NULL;
	}
	return (game);
}
