/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_initialize.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 21:27:05 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/01 21:28:53 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_check_initialize(t_game *game)
{
	if (!game || !game->player || !game->player->pos || !game->enemy || !game->enemy->pos)
		return(0);
	return(1);
}