/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:14:01 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/22 12:39:13 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
#include <fcntl.h>

# include "../libs/ft_printf/include/ft_printf.h"
# include "../libs/libft/include/libft.h"
# include "../libs/get_next_line/get_next_line.h"

# define PIXEL	16
# define PLAYER_STEP 16

# define NAME_WINDOW	"SO_LONG"
# define PATH_PLAYER	"./assets/knight.png"
# define PATH_FLOOR		"./assets/floor_1.png"
# define PATH_OBSTACLE		"./assets/wall_1.png"
# define PATH_EXIT		"./assets/door_closed.png"
# define PATH_PLAYER_UP		"./assets/Link_Down.png"
# define PATH_PLAYER_DOWN	"./assets/Link_Up.png"
# define PATH_ENEMY1	"./assets/enemy.png"
# define PATH_ENEMY2	"./assets/patrol.png"
# define PATHS_ENEMY	PATH_ENEMY1, PATH_ENEMY2
# define PATH_ITEM1		"./assets/bottle_navy.png"
# define PATH_ITEM2		"./assets/key.png"
# define PATH_ITEM3		"./assets/compass.png"
# define PATH_ITEM4		"./assets/map.png"
# define PATH_ITEM5		"./assets/heart.png"
# define PATHS_ITEM		PATH_ITEM1, PATH_ITEM2, PATH_ITEM3, PATH_ITEM4, PATH_ITEM5
# define AMOUNT_ENEMY	2
# define AMOUNT_ITEM	2

# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_borders
{
	int	minX;
	int	maxX;
	int	minY;
	int	maxY;
}		t_borders;

typedef struct s_pos
{
	int	x;
	int	y;
}		t_pos;

typedef struct s_asset
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;
	t_pos			*pos;
	struct s_asset	*next;
}					t_asset;

typedef struct s_exit
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;
	t_pos			*pos;
}				t_exit;

typedef struct s_player
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;
	t_pos			*pos;

	mlx_image_t		*move_image;
	int				moves;
	mlx_image_t		*item_image;
	int				item;
}					t_player;

typedef struct s_unique
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;
	t_pos			*pos;
}				t_unique;

typedef	struct	s_map
{
	char		*map_as_string;
	char		**map_as_arr;
	int			width;
	int			height;

}				t_map;


typedef struct s_game
{
	t_map		*map;
	mlx_t		*game_window;
	mlx_image_t	*game_image;
	t_exit		*exit;
	t_player	*player;
	int			item_total;

/**************************************/
	t_asset		**enemy;
	int			enemy_total;
	t_asset		**item;
	t_asset		*item_begin;
}				t_game;

// exit functions to free all memory properly
void		call_exit(t_game *game);
void		ft_exit_game(t_game *game);
void		ft_exit_asset(t_asset **asset, int amount);
void		ft_exit_pos(t_pos *pos);
void		ft_exit_player(t_player *player);
void		ft_exit_exit(t_exit *exit);
void		free_map_in_arr(char **map_in_arr);




// initialization functions
t_game		*ft_initialize_game(t_map *map);
t_player	*ft_initialize_player();
t_pos		*ft_initialize_pos(void);
t_exit		*ft_initialize_exit();
mlx_t		*ft_init_window(t_game *game);




t_asset 	**ft_initialize_asset(int amount);
void		start_game(t_game *game);
void		update_display_moves(t_game *game, int32_t posX, int32_t posY);
void		update_display_item(t_game *game, int32_t posX, int32_t posY);
void		ft_init_pos_asset(t_game *game, t_asset **asset, int amount);
t_asset 	*ft_initialize_item(t_game *game, int amount);
int			ft_load_textures_unique(t_game *game, mlx_image_t *image ,t_pos pos, const char *path);


// ????
int			check_file_type(char *str);
void		call_exit_map(t_map *map);
char **ft_arr_cpy(char **map_as_arr);


// load assets
t_pos		*get_pos_unique(char **map_as_arr, char c);
void		ft_load_textures_floor(t_game *game,char **map_as_arr);
void		ft_load_textures_obstacle(t_game *game,char **map_as_arr);

// load textures
int			ft_load_textures_enemy(t_game *game, const char* paths_asset[]);
int			ft_load_textures_player(t_game *game);
int			ft_load_textures_asset(t_game *game, t_asset **asset, const char* path[], int amount, t_pos pos);
int			ft_load_textures_exit(t_game *game);

// hook function
void		my_keyhook(mlx_key_data_t keydata, void *param);

// check functions
void		check_collision(t_game *game);
void		check_collect(t_game *game);
void		check_exit(t_game *game);



// start

// parsing
t_map		*parsing_input(char *map_input);
char		*map_to_string(char *path_map);
int			map_string_check(char *map_in_string);
int			map_arr_check(char **map_as_arr);
int			get_height(char **map_as_arr);


// debug functions
void 		print_2d_arr(char **map_in_arr);

// new libft functions
char	**ft_arr_cpy(char **map_as_arr);

#endif
