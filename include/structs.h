/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:09:56 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/25 16:39:28 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "so_long.h"

typedef struct s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct s_map
{
	char			*map_as_string;
	char			**map_as_arr;
	int				width;
	int				height;
}					t_map;

typedef struct s_exit
{
	mlx_texture_t	*texture_closed;
	mlx_texture_t	*texture_open;
	mlx_image_t		*image_closed;
	mlx_image_t		*image_open;
	t_pos			*pos;
}					t_exit;

typedef struct s_player
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;
	t_pos			*pos;
	mlx_image_t		*move_image;
	int				moves;
}					t_player;

typedef struct s_item
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;
	t_pos			*pos;
	int				collected;
}					t_item;

typedef struct s_game
{
	t_map			*map;
	mlx_t			*game_window;
	mlx_image_t		*game_image;
	t_exit			*exit;
	t_player		*player;
	mlx_image_t		*item_image;
	int				item_total;
	int				item_collect;
	t_item			**item;

	/**************************************/
	// t_asset		**enemy;
	// int			enemy_total;
}					t_game;

#endif
