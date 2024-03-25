/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures_obstacles.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:42:56 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/25 09:47:20 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_load_textures_obstacle_helper(t_game *game, char **map_as_arr,
		mlx_image_t *img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map_as_arr[y])
	{
		while (map_as_arr[y][x])
		{
			if (map_as_arr[y][x] == '1')
			{
				if (mlx_image_to_window(game->game_window, img, x * PIXEL, y
						* PIXEL) == -1)
					return (1);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int	ft_load_textures_obstacle(t_game *game, char **map_as_arr)
{
	mlx_texture_t	*obstacle_t;
	mlx_image_t		*obstacle_i;

	obstacle_t = mlx_load_png(PATH_OBSTACLE);
	if (!obstacle_t)
		return (1);
	obstacle_i = mlx_texture_to_image(game->game_window, obstacle_t);
	if (!obstacle_i)
		return (1);
	if (ft_load_textures_obstacle_helper(game, map_as_arr, obstacle_i))
		return (1);
	mlx_delete_texture(obstacle_t);
	return (0);
}
