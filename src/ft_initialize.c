/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:51:44 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/08 20:49:06 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_asset **ft_initialize_asset(void)
{
	int i;
	int j;
	t_asset **asset;

	i = 0;
	j = 0;
	asset = ft_calloc(sizeof(t_asset*) , AMOUNT_ENEMY);
	if(asset)
	{
		while(i < AMOUNT_ENEMY)
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
			if(game->player)
			{
				game->player->pos = NULL;
				game->player->pos = ft_initialize_pos();
				game->player->moves = 0;
			}
/**************************************************************/
			game->asset = NULL;
			game->asset = ft_initialize_asset();
			if(game->asset)
			{
				while(i < AMOUNT_ENEMY)
				{
					game->asset[i]->pos = NULL;
					game->asset[i]->pos = ft_initialize_pos();
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
