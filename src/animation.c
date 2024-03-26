/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:39:33 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/26 10:39:52 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	animation_player(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	game->frame += 1;
	if (game->frame == FRAME * 1)
	{
		game->player->image->instances[0].enabled = 1;
		game->player->image1->instances[0].enabled = 0;
		game->player->image2->instances[0].enabled = 0;
	}
	if (game->frame == FRAME * 2)
	{
		game->player->image->instances[0].enabled = 0;
		game->player->image1->instances[0].enabled = 1;
		game->player->image2->instances[0].enabled = 0;
	}
	if (game->frame == FRAME * 3)
	{
		game->player->image->instances[0].enabled = 0;
		game->player->image1->instances[0].enabled = 0;
		game->player->image2->instances[0].enabled = 1;
		game->frame = 0;
	}
}
