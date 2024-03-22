/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unused_at_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:54:21 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/22 12:50:41 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_show_address(t_game *game)
{
	printf("game		%p\n",(void*)&game);
	printf("game.image	%p\n",(void*)&game->game_image);
	printf("game.window	%p\n",(void*)&game->game_window);
}

void	print_2d_arr(char **map_in_arr)
{
	int i = 0;
	int j = 0;
	printf("	[0][1][2][3][4][5][7][8][9]\n");
	while(map_in_arr[i])
	{
		printf("[%i]	",i);
		while(map_in_arr[i][j])
		{
			printf(" %c ",map_in_arr[i][j]);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
}

t_unique	*ft_init_unique(t_map *map, char c)
{
	t_unique	*uni;

	uni = NULL;
	uni = ft_calloc(sizeof(t_player), 1);
	if (uni)
	{
		uni->pos = NULL;
		uni->pos = get_pos_unique(map->map_as_arr, c);
		if(!uni->pos)
		{
			free(uni);
			return(NULL);
		}
	}
	return (uni);
}
