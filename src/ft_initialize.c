/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:51:44 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/08 21:19:50 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_asset **ft_initialize_asset(int amount)
{
	int i;
	int j;
	t_asset **asset;

	i = 0;
	j = 0;
	asset = ft_calloc(sizeof(t_asset*) , amount);
	if(asset)
	{
		while(i < amount)
		{
			asset[i] = ft_calloc(sizeof(t_asset), 1);
			if(!asset[i])
			{
				while(j < i)
				{
					if(asset[j])
						free(asset[j]);
					j++;
				}
				if(asset)
					free(asset);
				return (NULL);
			}
			i++;
		}
	}
	return(asset);
}

t_player *ft_initialize_player(void)
{
	t_player *player;

	player = ft_calloc(sizeof(t_player), 1);
	if(player)
			{
				player->pos = NULL;
				player->pos = ft_initialize_pos();
				player->moves = 0;
			}
	return (player);
}

t_pos	*ft_initialize_pos(void)
{
	t_pos	*pos;

	pos = NULL;
	pos = ft_calloc(sizeof(t_pos), 1);
	return(pos);
}

t_game	*ft_initialize_game(void)
{
	int i;
	t_game	*game;

	i = 0;
	game = NULL;
	game = ft_calloc(sizeof(t_game), 1);
	if (game)
		{
/**************************************************************/
			game->player = NULL;
			game->player = ft_initialize_player();

/**************************************************************/
			game->enemy = NULL;
			game->enemy = ft_initialize_asset(AMOUNT_ENEMY);
			if(game->enemy)
			{
				while(i < AMOUNT_ENEMY)
				{
					game->enemy[i]->pos = NULL;
					game->enemy[i]->pos = ft_initialize_pos();
					i++;
				}
			}
/**************************************************************/
			game->item = NULL;
			game->item = ft_initialize_asset(AMOUNT_ITEM);
			if(game->item)
			{
				while(i < AMOUNT_ITEM)
				{
					game->item[i]->pos = NULL;
					game->item[i]->pos = ft_initialize_pos();
					i++;
				}
			}
/**************************************************************/
			game->game_window = NULL;
			game->game_image = NULL;
		}
	return (game);
}

int	ft_check_initialize(t_game *game)
{
	if (!game)
		return(0);

	return(1);
}
