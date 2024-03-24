/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 11:39:57 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/24 14:16:27 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_move_up(t_game *game)
{
	char	c;
	int		y;
	int		x;

	y = (game->player->image->instances[0].y) / PIXEL - 1;
	x = (game->player->image->instances[0].x) / PIXEL;
	c = game->map->map_as_arr[y][x];
	if (c != '1')
	{
		game->player->image->instances[0].y -= PLAYER_STEP;
		game->player->moves += 1;
		return (0);
	}
	return (1);
}

int	check_move_down(t_game *game)
{
	char	c;
	int		y;
	int		x;

	y = (game->player->image->instances[0].y) / PIXEL + 1;
	x = (game->player->image->instances[0].x) / PIXEL;
	c = game->map->map_as_arr[y][x];
	if (c != '1')
	{
		game->player->image->instances[0].y += PLAYER_STEP;
		game->player->moves += 1;
		return (0);
	}
	return (1);
}

int	check_move_left(t_game *game)
{
	char	c;
	int		y;
	int		x;

	y = (game->player->image->instances[0].y) / PIXEL;
	x = (game->player->image->instances[0].x) / PIXEL - 1;
	c = game->map->map_as_arr[y][x];
	if (c != '1')
	{
		game->player->image->instances[0].x -= PLAYER_STEP;
		game->player->moves += 1;
		return (0);
	}
	return (1);
}

int	check_move_right(t_game *game)
{
	char	c;
	int		y;
	int		x;

	y = (game->player->image->instances[0].y) / PIXEL;
	x = (game->player->image->instances[0].x) / PIXEL + 1;
	c = game->map->map_as_arr[y][x];
	if (c != '1')
	{
		game->player->image->instances[0].x += PLAYER_STEP;
		game->player->moves += 1;
		return (0);
	}
	return (1);
}
