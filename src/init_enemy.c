/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:11:01 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/26 15:50:55 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_exit_enemy(t_enemy *enemy)
{
	if (enemy)
	{
		if (enemy->pos)
			ft_exit_pos(enemy->pos);
		if (enemy->texture)
			mlx_delete_texture(enemy->texture);
		free(enemy);
	}
}

int	random_nbr_range(int min, int max)
{
	int	nbr;

	nbr = 0;
	srand(time(NULL));
	while(1)
	{
		nbr = arc4random_uniform(max);
		nbr = min + nbr % (max - min + 1);
		if(nbr <= max && nbr >= min)
			break;
	}
	return (nbr);
}

t_enemy	*ft_initialize_enemy(void)
{
	t_enemy	*enemy;

	enemy = NULL;
	enemy = ft_calloc(sizeof(t_enemy), 1);
	if (enemy)
	{
		enemy->pos = NULL;
		enemy->texture = NULL;
		enemy->image = NULL;
	}
	return (enemy);
}

int	get_enemy_pos(t_game *game, t_map *map)
{
	game->enemy->pos = ft_calloc(1, sizeof(t_pos));
	if (!game->enemy->pos)
		return (0);
	if (get_height(map->map_as_arr) > 10 && ft_strlen(map->map_as_arr[0]) > 10)
	{
		game->enemy->pos->y = random_nbr_range(1 ,10);
		game->enemy->pos->x = random_nbr_range(1 ,10);

		ft_printf("Random nbr is [%i][%i]\n", game->enemy->pos->y,game->enemy->pos->x);
	}
	return (0);
}
