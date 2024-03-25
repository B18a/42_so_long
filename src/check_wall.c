/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:26:13 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/25 12:34:44 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	check_first_row(char **map_as_arr, int len)
{
	int	i;

	i = 0;
	while (map_as_arr[0][i] && i < len && map_as_arr[0][i] == '1')
		i++;
	if (map_as_arr[0][i] && i < len && map_as_arr[0][i] != '1')
		return (1);
	return (0);
}

static int	check_sides(char **map_as_arr, int len, int height)
{
	int	i;

	i = 1;
	while (i <= height)
	{
		if (map_as_arr[i][0] != '1' || map_as_arr[i][len - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

static int	check_last_row(char **map_as_arr, int len, int height)
{
	int	i;

	i = 0;
	while (map_as_arr[height][i] && i < len && map_as_arr[height][i] == '1')
		i++;
	if (map_as_arr[height][i] && i < len && map_as_arr[height][i] != '1')
		return (1);
	return (0);
}

int	map_check_wall(char **map_as_arr)
{
	int	height;
	int	len;

	height = -1;
	if (!map_as_arr || !map_as_arr[0][0] || !map_as_arr[0])
		return (1);
	len = ft_strlen(map_as_arr[0]);
	while (map_as_arr[height + 1])
		height++;
	if (check_first_row(map_as_arr, len))
		return (1);
	if (check_sides(map_as_arr, len, height))
		return (1);
	if (check_last_row(map_as_arr, len, height))
		return (1);
	return (0);
}
