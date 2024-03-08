/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:14:01 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/08 12:29:28 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>

# define WIDTH	500
# define HEIGHT	500

# define NAME_WINDOW	"TEST"
# define PATH_PLAYER	"./assets/Link.png"
# define PATH_PLAYER_UP		"./assets/Link_Down.png"
# define PATH_PLAYER_DOWN	"./assets/Link_Up.png"
# define PATH_ENEMY1	"./assets/patrol.png"
# define PATH_ENEMY2	"./assets/patrol.png"
# define PATH_ENEMY3	"./assets/patrol.png"
# define PATH_ENEMY4	"./assets/patrol.png"
# define PATHS			PATH_ENEMY1, PATH_ENEMY2, PATH_ENEMY3, PATH_ENEMY4
# define AMOUNT_ASSETS	4

# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct s_assets
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;
	t_pos			*pos;
}				t_assets;

typedef struct s_player
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;
	mlx_image_t		*coordinates;
	t_pos			*pos;
	// mlx_texture_t	*texture_up;
	// mlx_image_t		*image_up;
	// mlx_texture_t	*texture_down;
	// mlx_image_t		*image_down;
}				t_player;

typedef struct s_game
{
	mlx_t		*game_window;
	mlx_image_t	*game_image;
	t_player	*player;
	t_assets	**assets;
}				t_game;

// libft
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
char	*ft_itoa(int n);


// exit functions to free all memory properly
void		call_exit(t_game *game);
int			ft_exit_game(t_game *game);
void		ft_exit_assets(t_game *game);

// initialization functions
t_game		*ft_initialize_game(void);
t_pos		*ft_initialize_pos(void);
int			ft_check_initialize(t_game *game);
t_assets	**ft_initialize_assets(void);
t_player *ft_initialize_player(void);


// load textures
int	ft_load_textures_assets(t_game *game, const char* paths_assets[]);
int	ft_load_textures_player(t_game *game);

// hook function
void		my_keyhook(mlx_key_data_t keydata, void *param);

#endif
