/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_cpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:29:16 by ajehle            #+#    #+#             */
/*   Updated: 2024/09/14 11:09:31 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**ft_arr_cpy(char **map_as_arr)
{
	int		i;
	char	**cpy;

	i = 0;
	cpy = NULL;
	while (map_as_arr[i])
		i++;
	cpy = ft_calloc(i + 1, sizeof(char *));
	if (!cpy)
		return (NULL);
	i = 0;
	while (map_as_arr[i])
	{
		cpy[i] = ft_calloc(ft_strlen(map_as_arr[i]) + 1, sizeof(char));
		// sleep(2);
		if (!cpy[i])
			return (free_map_in_arr(cpy), NULL);
		ft_memcpy(cpy[i], map_as_arr[i], ft_strlen(map_as_arr[i]) + 1);
		// printf("|%s|\n",cpy[i]);
		i++;
	}
	return (cpy);
}
