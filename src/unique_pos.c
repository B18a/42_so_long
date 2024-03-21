/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unique_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:11:58 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/21 15:12:07 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_pos	get_pos_unique(char **map_as_arr, char c)
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
			if(map_as_arr[y][x] == c)
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