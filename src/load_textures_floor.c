/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures_floor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:18:31 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/25 09:43:04 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_load_textures_floor_helper(t_game *game, char **map_as_arr,
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
			if (mlx_image_to_window(game->game_window, img, x * PIXEL, y
					* PIXEL) == -1)
				return (1);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int	ft_load_textures_floor(t_game *game, char **map_as_arr)
{
	mlx_texture_t	*floor_t;
	mlx_image_t		*floor_i;

	floor_t = NULL;
	floor_t = mlx_load_png(PATH_FLOOR);
	if (!floor_t)
		return (1);
	floor_i = mlx_texture_to_image(game->game_window, floor_t);
	if (!floor_i)
		return (1);
	if (ft_load_textures_floor_helper(game, map_as_arr, floor_i))
		return (1);
	mlx_delete_texture(floor_t);
	return (0);
}
