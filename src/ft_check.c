/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:02:40 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/22 14:56:45 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void check_enemy(t_game *game)
{
	t_borders	a;
	t_borders	b;
	int i;

	i = 0;
	a.minX = game->player->image->instances[0].x;
	a.maxX = game->player->image->instances[0].x + game->player->image->width;
	a.minY = game->player->image->instances[0].y;
	a.maxY = game->player->image->instances[0].y + game->player->image->height;
	while(i < game->enemy_total)
	{
		b.minX = game->enemy[i]->image->instances[0].x;
		b.maxX = game->enemy[i]->image->instances[0].x + game->enemy[0]->image->width;
		b.minY = game->enemy[i]->image->instances[0].y;
		b.maxY = game->enemy[i]->image->instances[0].y + game->enemy[0]->image->height;
		if((a.maxX >= b.minX) && (a.minX <= b.maxX) && (a.maxY >= b.minY) && (a.minY <= b.maxY))
			mlx_close_window(game->game_window);
		i++;
	}
}
// void check_collect(t_game *game)
// {
// 	t_borders	a;
// 	t_borders	b;
// 	int			i;

// 	i = 0;
// 	a.minX = game->player->image->instances[0].x;
// 	a.maxX = game->player->image->instances[0].x + game->player->image->width;
// 	a.minY = game->player->image->instances[0].y;
// 	a.maxY = game->player->image->instances[0].y + game->player->image->height;
// 	while(i < (game->item_total - game->player->item))
// 	{
// 		b.minX = game->item[i]->image->instances[0].x;
// 		b.maxX = game->item[i]->image->instances[0].x + game->item[0]->image->width;
// 		b.minY = game->item[i]->image->instances[0].y;
// 		b.maxY = game->item[i]->image->instances[0].y + game->item[0]->image->height;
// 		if((a.maxX >= b.minX) && (a.minX <= b.maxX) && (a.maxY >= b.minY) && (a.minY <= b.maxY))
// 		{
// 			game->item[i]->image->instances[0].enabled = 0;
// 			// game->item[i]->image->instances[0].z = -1;
// 			// mlx_delete_image(game->game_window, game->item[i]->image);
// 			game->player->item += 1;
// 		}
// 		i++;
// 	}
// }

void		check_exit(t_game *game)
{
	t_borders	a;
	t_borders	b;

	a.minX = game->player->image->instances[0].x;
	a.maxX = game->player->image->instances[0].x + game->player->image->width;
	a.minY = game->player->image->instances[0].y;
	a.maxY = game->player->image->instances[0].y + game->player->image->height;
	b.minX = game->exit->image->instances[0].x;
	b.maxX = game->exit->image->instances[0].x + game->exit->image->width;
	b.minY = game->exit->image->instances[0].y;
	b.maxY = game->exit->image->instances[0].y + game->exit->image->height;
	if((a.maxX >= b.minX) && (a.minX <= b.maxX) && (a.maxY >= b.minY) && (a.minY <= b.maxY))
	{
		if(game->item_total == game->player->item)
		{
			mlx_delete_image(game->game_window, game->exit->image);
			mlx_close_window(game->game_window);
			printf("FINISHED\n");
		}
	}
}
