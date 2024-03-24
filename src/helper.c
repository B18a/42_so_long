/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:16:00 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/24 13:47:49 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	get_item_total(char *map_as_string)
{
	int i;
	int item;

	i = 0;
	item = 0;
	while (map_as_string[i])
	{
		if (map_as_string[i] == 'C')
			item++;
		i++;
	}
	return (item);
}
