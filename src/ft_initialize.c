/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:51:44 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/02 10:44:46 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_assets **ft_initialize_assets(void)
{
	int i;
	int j;
	t_assets **assets;

	i = 0;
	j = 0;
	assets = ft_calloc(sizeof(t_assets*) , AMOUNT_ASSETS);
	// assets = malloc(sizeof(t_assets*) * AMOUNT_ASSETS);
	if(assets)
	{
		while(i < AMOUNT_ASSETS)
		{
			// assets[i] = malloc(sizeof(t_assets));
			assets[i] = ft_calloc(sizeof(t_assets), 1);
			if(!assets[i])
			{
				while(j < i)
				{
					if(assets[j])
						free(assets[j]);
					j++;
				}
				if(assets)
					free(assets);
				return (NULL);
			}
			i++;
		}
	}
	return(assets);
}


t_pos	*ft_initialize_pos(void)
{
	t_pos	*pos;

	pos = NULL;
	pos = ft_calloc(sizeof(t_pos), 1);
	// pos = malloc(sizeof(t_pos));
	return(pos);
}


t_player	*ft_initialize_player(void)
{
	t_player	*player;

	player = NULL;
	player = ft_calloc(sizeof(t_player), 1);
	// player = malloc(sizeof(t_player));
	if(player)
	{
		player->texture = NULL;
		player->image = NULL;
		player->pos = NULL;
		player->pos = ft_initialize_pos();
	}
	return (player);
}

t_game	*ft_initialize_game(void)
{
	int i;
	t_game	*game;

	i = 0;
	game = NULL;
	game = ft_calloc(sizeof(t_game), 1);
	// game = malloc(sizeof(t_game));
	if (game)
		{
			game->assets = NULL;
			game->assets = ft_initialize_assets();
			if(game->assets)
			{
				while(i < AMOUNT_ASSETS)
				{
					game->assets[i]->pos = NULL;
					game->assets[i]->pos = ft_initialize_pos();
					i++;
				}
			}

			game->game_window = NULL;
			game->game_image = NULL;

			game->player = NULL;
			game->player = ft_initialize_player();
			game->enemy = NULL;
			game->enemy = ft_initialize_player();
		}
	return (game);
}

int	ft_check_initialize(t_game *game)
{
	if (!game || !game->player || !game->player->pos || !game->enemy || !game->enemy->pos)
		return(0);
	return(1);
}
