/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_arr_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:00:45 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/24 14:43:19 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	map_check_rectangle(char **map_as_arr)
{
	int	i;

	i = 0;
	while (map_as_arr[i]
		&& (ft_strlen(map_as_arr[0]) == ft_strlen(map_as_arr[i])))
		i++;
	if (map_as_arr[i] && (ft_strlen(map_as_arr[0]) != ft_strlen(map_as_arr[i])))
		return (1);
	return (0);
}

int	map_check_wall(char **map_as_arr)
{
	int	i;
	int	height;
	int	len;

	i = 0;
	height = -1;
	if (!map_as_arr || !map_as_arr[0][0] || !map_as_arr[0])
		return (1);
	len = ft_strlen(map_as_arr[0]);
	while (map_as_arr[height + 1])
		height++;
	while (map_as_arr[0][i] && i < len && map_as_arr[0][i] == '1')
		i++;
	if (map_as_arr[0][i] && i < len && map_as_arr[0][i] != '1')
		return (1);
	i = 1;
	while (i <= height)
	{
		if (map_as_arr[i][0] != '1' || map_as_arr[i][len - 1] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (map_as_arr[height][i] && i < len && map_as_arr[height][i] == '1')
		i++;
	if (map_as_arr[height][i] && i < len && map_as_arr[height][i] != '1')
		return (1);
	return (0);
}

int	map_flood_fill(char **map, t_pos size, t_pos pos)
{
	if (pos.x < 0 || pos.x >= size.x || pos.y < 0 || pos.y >= size.y)
	{
		// printf("				Out of Map at [%i][%i]\n",pos.x, pos.y);
		return (1);
	}
	if (map[pos.x][pos.y] == '1')
	{
		// printf("				Wall at [%i][%i]\n",pos.x, pos.y);
		return (1);
	}
	if (map[pos.x][pos.y] == 'V')
	{
		// printf("				Visited at [%i][%i]\n",pos.x, pos.y);
		return (1);
	}
	if (map[pos.x][pos.y] == 'E')
	{
		// printf("				Exit at [%i][%i]\n",pos.x, pos.y);
		return (0);
	}
	map[pos.x][pos.y] = 'V';
	if (map_flood_fill(map, size, (t_pos){pos.x + 1, pos.y}) == 0
		|| map_flood_fill(map, size, (t_pos){pos.x - 1, pos.y}) == 0
		|| map_flood_fill(map, size, (t_pos){pos.x, pos.y + 1}) == 0
		|| map_flood_fill(map, size, (t_pos){pos.x, pos.y - 1}) == 0)
		return (0);
	return (1);
}

int	get_height(char **map_as_arr)
{
	int	i;

	i = 0;
	while (map_as_arr[i])
		i++;
	return (i);
}

int	map_arr_check(char **map_as_arr)
{
	int		status;
	t_pos	size;
	t_pos	*pos_player;
	char	**temp;

	temp = ft_arr_cpy(map_as_arr);
	status = 0;
	status += map_check_rectangle(map_as_arr);
	status += map_check_wall(map_as_arr);
	size.y = ft_strlen(map_as_arr[0]);
	size.x = get_height(map_as_arr);
	pos_player = get_pos_unique(map_as_arr, 'P');
	status += map_flood_fill(temp, size, (t_pos){pos_player->x, pos_player->y});
	free(pos_player);
	free_map_in_arr(temp);
	return (status);
}
