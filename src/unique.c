/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unique.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:11:58 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/25 09:56:37 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_pos	search_next(char **map_as_arr, int y, int x)
{
	while (map_as_arr[y])
	{
		while (map_as_arr[y][x])
		{
			if (map_as_arr[y][x] == 'C')
				return ((t_pos){x, y});
			x++;
		}
		x = 0;
		y++;
	}
	return ((t_pos){0, 0});
}

void	ft_init_pos_items(t_game *game)
{
	int		i;
	t_pos	temp;

	i = 0;
	temp = search_next(game->map->map_as_arr, game->item[i]->pos->x,
			game->item[i]->pos->y);
	game->item[i]->pos->y = temp.y;
	game->item[i]->pos->x = temp.x;
	i++;
	while (i < game->item_total)
	{
		temp = search_next(game->map->map_as_arr, game->item[i - 1]->pos->y,
				game->item[i - 1]->pos->x + 1);
		game->item[i]->pos->y = temp.y;
		game->item[i]->pos->x = temp.x;
		i++;
	}
}

t_pos	*get_pos_unique(char **map_as_arr, char c)
{
	t_pos	*pos;
	int		x;
	int		y;

	pos = NULL;
	x = 0;
	y = 0;
	pos = ft_calloc(1, sizeof(t_pos));
	if (!pos)
		return (NULL);
	while (map_as_arr[y])
	{
		while (map_as_arr[y][x])
		{
			if (map_as_arr[y][x] == c)
				return (pos->x = x, pos->y = y, pos);
			x++;
		}
		x = 0;
		y++;
	}
	return (pos);
}

int	ft_load_textures_unique(t_game *game, mlx_image_t *image, t_pos pos,
		const char *path)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	image = mlx_texture_to_image(game->game_window, texture);
	if (!image)
		return (call_exit(game), 0);
	if (mlx_image_to_window(game->game_window, image, pos.x * PIXEL, pos.y
			* PIXEL) == -1)
		return (call_exit(game), 0);
	return (0);
}
