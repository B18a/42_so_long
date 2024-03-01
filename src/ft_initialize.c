/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:51:44 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/01 21:40:15 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_pos	*ft_initialize_pos(void)
{
	t_pos	*pos;

	pos = NULL;
	pos = malloc(sizeof(t_pos));
	return(pos);
}


t_player	*ft_initialize_player(void)
{
	t_player	*player;

	player = NULL;
	player = malloc(sizeof(t_player));
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
	t_game	*game;

	game = NULL;
	game = malloc(sizeof(t_game));
	if (game)
		{
			game->player = NULL;
			game->game_window = NULL;
			game->game_image = NULL;
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