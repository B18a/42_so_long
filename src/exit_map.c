/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 13:53:48 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/24 13:54:33 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	call_exit_map(t_map *map)
{
	int	i;

	i = 0;
	if (map)
	{
		if (map->map_as_string)
		{
			free(map->map_as_string);
		}
		if (map->map_as_arr)
		{
			while (map->map_as_arr[i])
			{
				free(map->map_as_arr[i]);
				i++;
			}
			free(map->map_as_arr);
		}
		free(map);
	}
}

void	free_map_in_arr(char **map_in_arr)
{
	int	i;

	i = 0;
	if (map_in_arr)
	{
		while (map_in_arr[i])
		{
			free(map_in_arr[i]);
			i++;
		}
		free(map_in_arr);
	}
}
