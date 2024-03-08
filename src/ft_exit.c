/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:47:22 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/08 23:50:11 by ajehle           ###   ########.fr       */
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

void	ft_exit_asset(t_asset **asset, int amount)
{
	int	i;

	i = 0;
	while (i < amount)
	{
		if (asset[i]->pos)
			ft_exit_pos(asset[i]->pos);
		if (asset[i]->texture)
			mlx_delete_texture(asset[i]->texture);
		free(asset[i]);
		i++;
	}
	free(asset);
}

int	ft_exit_game(t_game *game)
{
	if (game)
		free (game);
	return (1);
}

void	ft_exit_exit(t_asset *exit)
{
	if(exit->pos)
		free(exit->pos);
	if(exit)
		free(exit);
}

void	call_exit(t_game *game)
{
	ft_exit_player(game);
	ft_exit_asset(game->enemy, game->enemy_total);
	ft_exit_asset(game->item, game->item_total);
	ft_exit_exit(game->exit);
	ft_exit_game(game);
}
