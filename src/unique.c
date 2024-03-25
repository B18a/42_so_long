/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unique.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:11:58 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/25 17:17:45 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_pos	search_next(char **map_as_arr, int y, int x)
{
	while (map_as_arr[y])
	{
		while (map_as_arr[y][x])
		{
			ft_printf("[%i][%i]:%c\n", y,x, map_as_arr[y][x]);
			if (map_as_arr[y][x] == 'C')
				return ((t_pos){x, y});
			x++;
		}
		x = 0;
		y++;
	}
	return ((t_pos){0, 0});
}

int	item_flood_fill(t_game *game, t_pos *pos)
{
	t_pos	size;
	char	**temp;

	temp = ft_arr_cpy(game->map->map_as_arr);
	if (!temp)
		return (1);

	size.x = ft_strlen(game->map->map_as_arr[0]);
	size.y = get_height(game->map->map_as_arr);
	if(map_flood_fill(temp, size, *pos))
	{
		free_map_in_arr(temp);
		return(1);
	}
	free_map_in_arr(temp);
	return(0);
}

int	init_pos_items(t_game *game)
{
	print_2d_arr(game->map->map_as_arr);
	int		i;
	t_pos	temp;

	i = 0;
	temp = search_next(game->map->map_as_arr, game->item[i]->pos->x,
			game->item[i]->pos->y);
	game->item[i]->pos->y = temp.y;
	game->item[i]->pos->x = temp.x;
	i++;
	ft_printf("POS[%i][%i]\n", temp.y, temp.x);
	while (i < game->item_total)
	{
		temp = search_next(game->map->map_as_arr, game->item[i - 1]->pos->y,
				game->item[i - 1]->pos->x + 1);
		game->item[i]->pos->y = temp.y;
		game->item[i]->pos->x = temp.x;
		print_2d_arr(game->map->map_as_arr);
		ft_printf("POS[%i][%i]\n", temp.y, temp.x);
		if (!item_flood_fill(game, game->item[i]->pos))
			return (0);
		i++;
	}
	return (1);
}

t_pos	*get_pos_unique(char **map_as_arr, char c)
{
	t_pos	*pos;
	int		x;
	int		y;

	pos = NULL;
	y = 0;
	pos = ft_calloc(1, sizeof(t_pos));
	if (!pos)
		return (NULL);
	while (map_as_arr[y])
	{
		x = 0;
		while (map_as_arr[y][x])
		{
			if (map_as_arr[y][x] == c)
				return (pos->x = x, pos->y = y, pos);
			x++;
		}
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
