/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:00:45 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/26 10:48:45 by ajehle           ###   ########.fr       */
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

int	map_flood_fill(char **map, t_pos size, t_pos pos)
{
	if (pos.x <= 0 || pos.x >= size.x || pos.y <= 0 || pos.y >= size.y)
		return (0);
	if (map[pos.y][pos.x] == '1')
		return (0);
	if (map[pos.y][pos.x] == 'E')
		return (1);
	map[pos.y][pos.x] = '1';
	if (map_flood_fill(map, size, (t_pos){pos.x + 1, pos.y}))
		return (1);
	if (map_flood_fill(map, size, (t_pos){pos.x - 1, pos.y}))
		return (1);
	if (map_flood_fill(map, size, (t_pos){pos.x, pos.y + 1}))
		return (1);
	if (map_flood_fill(map, size, (t_pos){pos.x, pos.y - 1}))
		return (1);
	return (0);
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

	status = 0;
	status += map_check_rectangle(map_as_arr);
	if (status)
		return (1);
	status += map_check_wall(map_as_arr);
	if (status)
		return (1);
	size.x = ft_strlen(map_as_arr[0]);
	size.y = get_height(map_as_arr);
	temp = ft_arr_cpy(map_as_arr);
	if (!temp)
		return (1);
	pos_player = get_pos_unique(map_as_arr, 'P');
	if (pos_player)
		if (!map_flood_fill(temp, size, (t_pos){pos_player->x, pos_player->y}))
			status += 1;
	free(pos_player);
	free_map_in_arr(temp);
	return (status);
}
