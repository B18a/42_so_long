/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:02:40 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/24 13:47:09 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_for_item(t_game *game, char c, int posY, int posX)
{
	int	i;

	i = 0;
	if (!(c == 'C'))
		return ;
	while (i < game->item_total)
	{
		if (game->item[i]->pos->y == posY && game->item[i]->pos->x == posX
			&& !game->item[i]->collected)
		{
			game->item[i]->collected = 1;
			game->item[i]->image->instances->enabled = 0;
			game->item_collect += 1;
			return ;
		}
		i++;
	}
	return ;
}

void	check_for_exit(t_game *game, char c, int posY, int posX)
{
	if (!(c == 'E'))
		return ;
	if (game->exit->pos->y == posY && game->exit->pos->x == posX
		&& game->exit->image_open->enabled
		&& game->exit->image_open->instances->enabled)
	{
		mlx_close_window(game->game_window);
	}
	return ;
}
