/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:47:22 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/24 13:54:40 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_exit_pos(t_pos *pos)
{
	if (pos)
		free(pos);
}

void	ft_exit_player(t_player *player)
{
	if (player->pos)
		ft_exit_pos(player->pos);
	if (player->texture)
		mlx_delete_texture(player->texture);
	if (player)
		free(player);
}

void	ft_exit_exit(t_exit *exit)
{
	if (exit->pos)
		free(exit->pos);
	if (exit->texture_closed)
		mlx_delete_texture(exit->texture_closed);
	if (exit->texture_open)
		mlx_delete_texture(exit->texture_open);
	if (exit)
		free(exit);
}

void	ft_exit_item(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->item_total)
	{
		if (game->item[i]->pos)
			free(game->item[i]->pos);
		free(game->item[i]);
		i++;
	}
	if (game->item)
		free(game->item);
}

void	call_exit(t_game *game)
{
	call_exit_map(game->map);
	ft_exit_player(game->player);
	ft_exit_exit(game->exit);
	ft_exit_item(game);
	if (game)
		free(game);
}
