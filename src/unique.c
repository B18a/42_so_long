/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unique.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:11:58 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/22 10:17:02 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_pos	*get_pos_unique(char **map_as_arr, char c)
{
	t_pos	*pos;
	int		x;
	int		y;

	pos = ft_calloc(1,sizeof(t_pos));
	x = 0;
	y = 0;
	pos->x = 0;
	pos->y = 0;
	while(map_as_arr[y])
	{
		while(map_as_arr[y][x])
		{
			if(map_as_arr[y][x] == c)
			{
				pos->x = x;
				pos->y = y;
				return(pos);
			}
			x++;
		}
		x = 0;
		y++;
	}
	printf("%c [%i][%i] \n",c, pos->y, pos->x);
	return(pos);
}

int	ft_load_textures_unique(t_game *game, mlx_image_t *image ,t_pos pos, const char *path)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	image = mlx_texture_to_image(game->game_window, texture);
	if(!image)
		return (call_exit(game), 0);
	if(mlx_image_to_window(game->game_window, image, pos.x * PIXEL, pos.y * PIXEL))
		return (call_exit(game), 0);
	return(0);
}