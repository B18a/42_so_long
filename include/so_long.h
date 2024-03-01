/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:14:01 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/01 21:31:46 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>

# include "../MLX42/include/MLX42/MLX42.h"

# define WIDTH	500
# define HEIGHT	500

typedef struct s_pos
{
	int			x;
	int			y;
}				t_pos;


typedef struct s_player
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;
	t_pos			*pos;
}				t_player;

typedef struct s_game
{
	mlx_t		*game_window;
	mlx_image_t	*game_image;
	t_player	*player;
	t_player	*enemy;
}				t_game;

// exit functions to free all memory properly
void		call_exit(t_game *game);
int			ft_exit_game(t_game *game);
int			ft_exit_player(t_game *game, t_player *player);

// initialization functions
t_player	*ft_initialize_player(void);
t_game		*ft_initialize_game(void);
t_pos		*ft_initialize_pos(void);
int			ft_check_initialize(t_game *game);

// hook function
void my_keyhook(mlx_key_data_t keydata, void *param);



#endif