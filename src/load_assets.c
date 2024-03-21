/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:50:38 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/21 11:24:06 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_pos	get_pos_player(char **map_as_arr)
{
	t_pos	pos;
	int		x;
	int		y;

	x = 0;
	y = 0;
	pos.x = 0;
	pos.y = 0;
	while(map_as_arr[y])
	{
		while(map_as_arr[y][x])
		{
			if(map_as_arr[y][x] == 'P')
			{
				pos.x = x;
				pos.y = y;
				return(pos);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return(pos);
}

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

