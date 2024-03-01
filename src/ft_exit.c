/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:47:22 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/01 14:26:39 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

// images are freed by mlx terminate

int	ft_exit_game(t_game *game)
{
	if(game)
	{
		// if (game->player)
		// {
		// 	if (game->player->texture)
		// 		free(game->player->texture);
		// 	if (game->player->pos)
		// 		free(game->player->pos);
		// 	free(game->player);
		// }
		free(game);
	}
	return (1);
}

void	call_exit(t_game *game)
{
	ft_exit_game(game);
}
