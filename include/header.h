/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:14:01 by ajehle            #+#    #+#             */
/*   Updated: 2024/02/17 10:09:23 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define	HEADER_H

// printf lib
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#include"../MLX42/include/MLX42/MLX42.h"


typedef struct	s_player
{
	int				x_pos_player;
	int				y_pos_player;
	mlx_texture_t	*texture;
	mlx_image_t		*image;
}				t_player;

typedef struct	s_game
{
	mlx_t		*game_window;
	mlx_image_t	*game_image;
	t_player	*player;
}				t_game;





#endif