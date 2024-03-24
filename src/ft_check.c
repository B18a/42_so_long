/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:02:40 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/24 11:42:01 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_for_item(t_game *game, char c,int posY, int posX)
{
	int	i;

	i = 0;
	if(!(c == 'C'))
		return;
	while(i < game->item_total)
	{
		if(game->item[i]->pos->y == posY && game->item[i]->pos->x == posX && !game->item[i]->collected)
		{
			game->item[i]->collected = 1;
			game->item[i]->image->instances->enabled = 0;
			game->item_collect += 1;
			return;
		}
		i++;
	}
	return;
}
// void		check_exit(t_game *game)
// {
// 	t_borders	a;
// 	t_borders	b;

// 	a.minX = game->player->image->instances[0].x;
// 	a.maxX = game->player->image->instances[0].x + game->player->image->width;
// 	a.minY = game->player->image->instances[0].y;
// 	a.maxY = game->player->image->instances[0].y + game->player->image->height;
// 	b.minX = game->exit->image->instances[0].x;
// 	b.maxX = game->exit->image->instances[0].x + game->exit->image->width;
// 	b.minY = game->exit->image->instances[0].y;
// 	b.maxY = game->exit->image->instances[0].y + game->exit->image->height;
// 	if((a.maxX >= b.minX) && (a.minX <= b.maxX) && (a.maxY >= b.minY) && (a.minY <= b.maxY))
// 	{
// 		if(game->item_total == game->item_collect)
// 		{
// 			mlx_delete_image(game->game_window, game->exit->image);
// 			mlx_close_window(game->game_window);
// 			printf("FINISHED\n");
// 		}
// 	}
// }
