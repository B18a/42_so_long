/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:47:22 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/01 22:36:37 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_exit_pos(t_pos *pos)
{
	if (pos)
		free (pos);
	return (1);
}

int	ft_exit_asset(t_game *game, t_player *asset)
{
	if (asset)
	{
		if (asset->pos)
			ft_exit_pos(asset->pos);
		if (asset->texture)
			mlx_delete_texture(asset->texture);
		if (asset->image && game->game_window)
			mlx_delete_image(game->game_window, asset->image);
		free(asset);
	}
	return (1);
}

int	ft_exit_game(t_game *game)
{
	if (game)
		free (game);
	return (1);
}


void ft_exit_assets(t_game *game)
{
	int i;

	i = 0;
	if(game->assets)
	{
		while(i < game->amount_assets)
		{
			if(game->assets[i])
				free(game->assets[i]);
			i++;
		}
		free(game->assets);
	}
}

void	call_exit(t_game *game)
{
	ft_exit_assets(game);
	ft_exit_asset(game, game->player);
	ft_exit_asset(game, game->enemy);
	ft_exit_game(game);
}
