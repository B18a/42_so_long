/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:50:38 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/24 12:02:43 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_load_textures_floor(t_game *game,char **map_as_arr)
{
	mlx_texture_t	*floor_t;
	mlx_image_t		*floor_i;
	int				x;
	int				y;

	x = 0;
	y = 0;
	floor_t = mlx_load_png(PATH_FLOOR);
	floor_i = mlx_texture_to_image(game->game_window, floor_t);
	// if(!floor_i)
	// checking and exiting!!!!
	while(map_as_arr[y])
	{
		while(map_as_arr[y][x])
		{
			if(mlx_image_to_window(game->game_window, floor_i, x * PIXEL, y * PIXEL))
			{
				// checking and exiting!!!!
			}
			x++;
		}
		x = 0;
		y++;
	}
	mlx_delete_texture(floor_t);
}

void	ft_load_textures_obstacle(t_game *game,char **map_as_arr)
{
	mlx_texture_t	*obstacle_t;
	mlx_image_t		*obstacle_i;
	int				x;
	int				y;

	x = 0;
	y = 0;
	obstacle_t = mlx_load_png(PATH_OBSTACLE);
	obstacle_i = mlx_texture_to_image(game->game_window, obstacle_t);
	// if(!obstacle_i)
	// checking and exiting!!!!
	while(map_as_arr[y])
	{
		while(map_as_arr[y][x])
		{
			if(map_as_arr[y][x] == '1')
			{
				if(mlx_image_to_window(game->game_window, obstacle_i, x * PIXEL, y * PIXEL))
				{
					// checking and exiting!!!!
				}
			}
			x++;
		}
		x = 0;
		y++;
	}
	mlx_delete_texture(obstacle_t);
}

int	ft_load_textures_player(t_game *game)
{
		game->player->texture = mlx_load_png(PATH_PLAYER);
		game->player->image = mlx_texture_to_image(game->game_window, game->player->texture);
			if(!game->player->image)
			return (call_exit(game), 0);
		if(mlx_image_to_window(game->game_window, game->player->image, game->player->pos->x * PIXEL, game->player->pos->y * PIXEL))
			return (call_exit(game), 0);
		return(0);
}

int	ft_load_textures_exit(t_game *game)
{
	game->exit->texture_closed = mlx_load_png(PATH_EXIT_CLOSED);
	game->exit->image_closed = mlx_texture_to_image(game->game_window, game->exit->texture_closed);
	if(!game->exit->image_closed)
		return (call_exit(game), 0);
	if(mlx_image_to_window(game->game_window, game->exit->image_closed, game->exit->pos->x * PIXEL, game->exit->pos->y * PIXEL))
		return (call_exit(game), 0);
	game->exit->texture_open = mlx_load_png(PATH_EXIT_OPEN);
	game->exit->image_open = mlx_texture_to_image(game->game_window, game->exit->texture_open);
	if(!game->exit->image_open)
		return (call_exit(game), 0);
	if(mlx_image_to_window(game->game_window, game->exit->image_open, game->exit->pos->x * PIXEL, game->exit->pos->y * PIXEL))
		return (call_exit(game), 0);
	game->exit->image_open->instances->enabled = 0;
	return(0);
}
