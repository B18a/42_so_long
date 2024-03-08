/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:14:01 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/08 23:51:12 by ajehle           ###   ########.fr       */
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

# define PLAYER_STEP 64

# define NAME_WINDOW	"TEST"
# define PATH_PLAYER	"./assets/Link.png"
# define PATH_PLAYER_UP		"./assets/Link_Down.png"
# define PATH_PLAYER_DOWN	"./assets/Link_Up.png"
# define PATH_ENEMY1	"./assets/enemy.png"
# define PATH_ENEMY2	"./assets/patrol.png"
# define PATH_FLOOR		"./assets/Grass.png"
# define PATHS_ENEMY	PATH_ENEMY1, PATH_ENEMY2
# define PATH_ITEM1		"./assets/bottle_navy.png"
# define PATH_ITEM2		"./assets/key.png"
# define PATH_ITEM3		"./assets/compass.png"
# define PATH_ITEM4		"./assets/map.png"
# define PATH_ITEM5		"./assets/heart.png"
# define PATHS_ITEM		PATH_ITEM1, PATH_ITEM2, PATH_ITEM3, PATH_ITEM4, PATH_ITEM5
# define AMOUNT_ENEMY	2
# define AMOUNT_ITEM	1
# define PATH_EXIT		"./assets/heart.png"

# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct s_asset
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;
	t_pos			*pos;
}				t_asset;

typedef struct s_player
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	mlx_image_t		*width;
	mlx_image_t		*height;
	t_pos			*pos;
	mlx_image_t		*move_image;
	int				moves;
	mlx_image_t		*item_image;
	int				item;
	// mlx_texture_t	*texture_up;
	// mlx_image_t		*image_up;
	// mlx_texture_t	*texture_down;
	// mlx_image_t		*image_down;
}				t_player;

typedef struct s_game
{
	mlx_t		*game_window;
	mlx_image_t	*game_image;
	t_asset		*exit;
	t_player	*player;
	t_asset		**enemy;
	int			enemy_total;
	t_asset		**item;
	int			item_total;
}				t_game;

// libft
void		*ft_calloc(size_t count, size_t size);
void		ft_bzero(void *s, size_t n);
void		*ft_memset(void *b, int c, size_t len);
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
char		*ft_itoa(int n);

// exit functions to free all memory properly
void		call_exit(t_game *game);
int			ft_exit_game(t_game *game);
void		ft_exit_asset(t_asset **asset, int amount);
void		ft_exit_exit(t_asset *exit);
int			ft_exit_pos(t_pos *pos);

// initialization functions
t_game		*ft_initialize_game(void);
t_pos		*ft_initialize_pos(void);
t_asset 	**ft_initialize_asset(int amount);
t_player	*ft_initialize_player(void);
void		start_game(t_game *game);
void		update_display_moves(t_game *game, int32_t posX, int32_t posY);
void		update_display_item(t_game *game, int32_t posX, int32_t posY);
void		ft_init_pos_asset(t_game *game, t_asset **asset, int amount);


// load textures
int			ft_load_textures_enemy(t_game *game, const char* paths_asset[]);
int			ft_load_textures_player(t_game *game, int posX, int posY);
int			ft_load_textures_asset(t_game *game, t_asset **asset, const char* path[], int amount, t_pos pos);
int			ft_load_textures_exit(t_game *game, t_asset *exit, const char* path, t_pos pos);

// hook function
void		my_keyhook(mlx_key_data_t keydata, void *param);

// ????
void		check_collision(t_game *game);
void		check_collect(t_game *game);
void		check_exit(t_game *game);


#endif
