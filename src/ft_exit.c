/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:47:22 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/08 14:07:23 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_exit_pos(t_pos *pos)
{
	if (pos)
		free (pos);
	return (1);
}



void ft_exit_player(t_game *game)
{
	if (game->player->pos)
		ft_exit_pos(game->player->pos);
	if (game->player->texture)
		mlx_delete_texture(game->player->texture);
	free(game->player);

}
void ft_exit_assets(t_game *game)
{
	int i;

	i = 0;
	while(i < AMOUNT_ASSETS)
	{

			if (game->assets[i]->pos)
				ft_exit_pos(game->assets[i]->pos);
			if (game->assets[i]->texture)
				mlx_delete_texture(game->assets[i]->texture);

			free(game->assets[i]);
		i++;
	}
	free(game->assets);
}


int	ft_exit_game(t_game *game)
{
	if (game)
		free (game);
	return (1);
}

void	call_exit(t_game *game)
{
	ft_exit_player(game);
	ft_exit_assets(game);
	ft_exit_game(game);
}
