/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:47:22 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/01 20:42:15 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// images are freed by mlx terminate

int ft_exit_pos(t_pos *pos)
{
	if(pos)
		free(pos);
	return (1);
}

int	ft_exit_player(t_game *game, t_player *player)
{
	if(player)
	{
		if (player->pos)
			ft_exit_pos(player->pos);
		if (player->texture)
			mlx_delete_texture(player->texture);
		if (player->image && game->game_window)
			mlx_delete_image(game->game_window, player->image);
		free(player);
	}
	return (1);

}

int	ft_exit_game(t_game *game)
{
	if(game)
		free(game);
	return (1);
}

void	call_exit(t_game *game)
{
	ft_exit_player(game, game->player);
	ft_exit_player(game, game->enemy);
	ft_exit_game(game);
}
