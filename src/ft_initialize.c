/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:51:44 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/08 11:20:38 by ajehle           ###   ########.fr       */
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
	if(assets)
	{
		while(i < AMOUNT_ASSETS)
		{
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
			}
/**************************************************************/
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
