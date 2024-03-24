/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:47:22 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/24 13:47:16 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	call_exit_map(t_map *map)
{
	int	i;

	i = 0;
	if (map)
	{
		if (map->map_as_string)
		{
			free(map->map_as_string);
		}
		if (map->map_as_arr)
		{
			while (map->map_as_arr[i])
			{
				free(map->map_as_arr[i]);
				i++;
			}
			free(map->map_as_arr);
		}
		free(map);
	}
}

void	free_map_in_arr(char **map_in_arr)
{
	int	i;

	i = 0;
	if (map_in_arr)
	{
		while (map_in_arr[i])
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
		free(pos);
}

void	ft_exit_player(t_player *player)
{
	if (player->pos)
		ft_exit_pos(player->pos);
	if (player->texture)
		mlx_delete_texture(player->texture);
	if (player)
		free(player);
}

void	ft_exit_game(t_game *game)
{
	if (game)
		free(game);
}

void	ft_exit_exit(t_exit *exit)
{
	if (exit->pos)
		free(exit->pos);
	if (exit->texture_closed)
		mlx_delete_texture(exit->texture_closed);
	if (exit->texture_open)
		mlx_delete_texture(exit->texture_open);
	if (exit)
		free(exit);
}

void	ft_exit_item(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->item_total)
	{
		if (game->item[i]->pos)
			free(game->item[i]->pos);
		// if(game->item[i]->texture)
		// 	mlx_delete_texture(game->item[i]->texture);
		free(game->item[i]);
		i++;
	}
	if (game->item)
		free(game->item);
}

void	call_exit(t_game *game)
{
	call_exit_map(game->map);
	ft_exit_player(game->player);
	ft_exit_exit(game->exit);
	ft_exit_item(game);
	ft_exit_game(game);
}
