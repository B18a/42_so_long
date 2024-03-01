/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:47:22 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/01 13:10:32 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

// images are freed by mlx terminate

int	ft_exit_player(t_player *player)
{
	if (player)
	{
		// if (player->texture)
		// 	free(player->texture);
		if (player->pos)
			free(player->pos);
		free(player);
	}
	return (1);
}

int	ft_exit_game(t_game *game)
{
	if(game)
	{
		// if (game->game_window)
		// 	free(game->game_window);
		free(game);
	}
	return (1);
}

void	call_exit(t_game *game)
{
	// ft_exit_player(game->player);
	ft_exit_game(game);
}
