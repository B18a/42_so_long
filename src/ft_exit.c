/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:47:22 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/21 10:55:48 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	call_exit_prep(char *map_as_string, char **map_as_arr)
{
	int i;

	i = 0;
	if(map_as_string)
		free(map_as_string);
	if(map_as_arr)
	{
	while(map_as_arr[i])
	{
		free(map_as_arr[i]);
		i++;
	}
	free(map_as_arr);
	}
}

void	free_map_in_arr(char **map_in_arr)
{
	int i;

	i = 0;
	if(map_in_arr)
	{
		while(map_in_arr[i])
		{
			free(map_in_arr[i]);
			i++;
		}
		free(map_in_arr);
	}
}

void	ft_exit_pos(t_pos *pos)
{
	if (pos)
		free (pos);
}

void	ft_exit_player(t_player *player)
{
	if (player->pos)
		ft_exit_pos(player->pos);
	if (player->texture)
		mlx_delete_texture(player->texture);
	free(player);
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

void	ft_exit_game(t_game *game)
{
	if (game)
		free (game);
}

void	ft_exit_exit(t_asset *exit)
{
	if(exit->pos)
		free(exit->pos);
	if(exit->texture)
		mlx_delete_texture(exit->texture);
	if(exit)
		free(exit);
}

void	call_exit(t_game *game)
{
	ft_exit_player(game->player);
	ft_exit_asset(game->enemy, game->enemy_total);
	ft_exit_asset(game->item, game->item_total);
	ft_exit_exit(game->exit);
	ft_exit_game(game);
}
