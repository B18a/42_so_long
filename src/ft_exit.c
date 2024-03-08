/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:47:22 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/08 16:26:05 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_exit_pos(t_pos *pos)
{
	if (pos)
		free (pos);
	return (1);
}

void	ft_exit_player(t_game *game)
{
	if (game->player->pos)
		ft_exit_pos(game->player->pos);
	if (game->player->texture)
		mlx_delete_texture(game->player->texture);
	free(game->player);
}

void	ft_exit_enemy(t_game *game)
{
	int	i;

	i = 0;
	while (i < AMOUNT_ENEMY)
	{
		if (game->enemy[i]->pos)
			ft_exit_pos(game->enemy[i]->pos);
		if (game->enemy[i]->texture)
			mlx_delete_texture(game->enemy[i]->texture);
		free(game->enemy[i]);
		i++;
	}
	free(game->enemy);
}

int	ft_exit_game(t_game *game)
{
	if (game)
		free (game);
	return (1);
}

void	call_exit(t_game *game)
{
	ft_exit_player(game);
	ft_exit_enemy(game);
	ft_exit_game(game);
}
