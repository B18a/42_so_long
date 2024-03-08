/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collect_collision.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:02:40 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/08 22:37:33 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void check_collision(t_game *game)
{
	int aminX;
	int amaxX;
	int aminY;
	int amaxY;
	int bminX;
	int bmaxX;
	int bminY;
	int bmaxY;
	int i;

	i = 0;
	aminX = game->player->image->instances[0].x;
	amaxX = game->player->image->instances[0].x + game->player->image->width;
	aminY = game->player->image->instances[0].y;
	amaxY = game->player->image->instances[0].y + game->player->image->height;
	while(i < AMOUNT_ENEMY)
	{
		bminX = game->enemy[i]->image->instances[0].x;
		bmaxX = game->enemy[i]->image->instances[0].x + game->enemy[0]->image->width;
		bminY = game->enemy[i]->image->instances[0].y;
		bmaxY = game->enemy[i]->image->instances[0].y + game->enemy[0]->image->height;
		if((amaxX >= bminX) && (aminX <= bmaxX) && (amaxY >= bminY) && (aminY <= bmaxY))
			mlx_close_window(game->game_window);
		i++;
	}
}
void check_collect(t_game *game)
{
	int aminX;
	int amaxX;
	int aminY;
	int amaxY;
	int bminX;
	int bmaxX;
	int bminY;
	int bmaxY;
	int i;

	i = 0;
	aminX = game->player->image->instances[0].x;
	amaxX = game->player->image->instances[0].x + game->player->image->width;
	aminY = game->player->image->instances[0].y;
	amaxY = game->player->image->instances[0].y + game->player->image->height;
	while(i < (game->item_total - game->player->item))
	{
		bminX = game->item[i]->image->instances[0].x;
		bmaxX = game->item[i]->image->instances[0].x + game->item[0]->image->width;
		bminY = game->item[i]->image->instances[0].y;
		bmaxY = game->item[i]->image->instances[0].y + game->item[0]->image->height;
		if((amaxX >= bminX) && (aminX <= bmaxX) && (amaxY >= bminY) && (aminY <= bmaxY))
		{
			mlx_delete_image(game->game_window, 	game->item[i]->image);
			game->player->item += 1;
		}
		i++;
	}
}