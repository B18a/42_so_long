/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:47:22 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/02 11:17:31 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_exit_pos(t_pos *pos)
{
	if (pos)
		free (pos);
	return (1);
}



void ft_exit_assets(t_game *game)
{
	int i;

	i = 0;
	// if(game->assets)
	// {
		while(i < AMOUNT_ASSETS)
		{
			// if(game->assets[i])
			// {
				if (game->assets[i]->pos)
					ft_exit_pos(game->assets[i]->pos);
				if (game->assets[i]->texture)
					mlx_delete_texture(game->assets[i]->texture);
				// if (game->assets[i]->image && game->game_window)
				// 	mlx_delete_image(game->game_window, game->assets[i]->image);
				free(game->assets[i]);
			// }
			i++;
		}
		free(game->assets);
	// }
}


int	ft_exit_game(t_game *game)
{
	if (game)
		free (game);
	return (1);
}

void	call_exit(t_game *game)
{
	ft_exit_assets(game);
	ft_exit_game(game);
}
