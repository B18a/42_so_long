/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:14:01 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/26 15:51:05 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libs/ft_printf/include/ft_printf.h"
# include "../libs/get_next_line/get_next_line.h"
# include "../libs/libft/include/libft.h"
# include "defs.h"
# include "structs.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

// animation
void		animation_player(void *param);

// move enemy
void		move_enemy(void *param);

// ft_arr_cpy
char		**ft_arr_cpy(char **map_as_arr);

// check
void		check_for_item(t_game *game, char c, int posY, int posX);
void		check_for_exit(t_game *game, char c, int posY, int posX);

// exit map
void		call_exit_map(t_map *map);
void		free_map_in_arr(char **map_in_arr);

// exit
void		ft_exit_pos(t_pos *pos);
void		ft_exit_player(t_player *player);
void		ft_exit_exit(t_exit *exit);
void		ft_exit_item(t_game *game);
void		call_exit(t_game *game);

// hook
void		my_keyhook(mlx_key_data_t keydata, void *param);
void		update_display(t_game *game, int pos_y, int pos_x);

// init_helper
t_exit		*ft_initialize_exit(void);
t_player	*ft_initialize_player(void);
mlx_t		*ft_init_window(t_game *game);
t_game		*ft_initialize_game(t_map *map);

// init_item
t_item		**ft_initialize_item(t_game *game);

// init_enemy
t_enemy		*ft_initialize_enemy(void);
int			get_enemy_pos(t_game *game, t_map *map);
void		ft_exit_enemy(t_enemy *enemy);
int			random_nbr_range(int min, int max);

// init_main
t_game		*ft_initialize(t_map *map);

// helper
int			get_item_total(char *map_as_string);

// load_textures
int			ft_load_textures_item(t_game *game);
int			ft_load_textures_obstacle(t_game *game, char **map_as_arr);
int			ft_load_textures_player(t_game *game);
int			ft_load_textures_exit(t_game *game);
int			ft_load_textures_enemy(t_game *game);

// load_textures_helper
int			ft_load_textures_floor_helper(t_game *game, char **map_as_arr,
				mlx_image_t *img);
int			ft_load_textures_floor(t_game *game, char **map_as_arr);
int			ft_load_textures_obstacle(t_game *game, char **map_as_arr);
int			ft_load_textures_obstacle_helper(t_game *game, char **map_as_arr,
				mlx_image_t *img);

// main
void		start_game(t_game *game);
t_map		*parsing_input(char *map_input);
int			load_textures(t_game *game);

// map_arr_check
int			map_check_rectangle(char **map_as_arr);
int			map_check_wall(char **map_as_arr);
int			map_flood_fill(char **map, t_pos size, t_pos pos);
int			get_height(char **map_as_arr);
int			map_arr_check(char **map_as_arr);

// map_string_check
int			forbidden_char(char c);
int			ft_map_check_chars(char *map_in_string);
int			ft_check_unique_char(char *map_as_string, char character);
int			ft_check_multiple_char(char *map_as_string, char character);
int			map_string_check(char *map_as_string);

// moves
int			check_move_up(t_game *game);
int			check_move_down(t_game *game);
int			check_move_left(t_game *game);
int			check_move_right(t_game *game);

// parsing
char		*map_to_string(char *path_map);
char		*read_map(char *map);
int			check_file_type(char *str);

// unique
t_pos		search_next(char **map_as_arr, int y, int x);
int			init_pos_items(t_game *game);
t_pos		*get_pos_unique(char **map_as_arr, char c);
int			ft_load_textures_unique(t_game *game, mlx_image_t *image, t_pos pos,
				const char *path);
int			item_exit_check(t_game *game, t_pos *pos);

// update_display
void		update_display_exit(t_game *game);
int			update_display_item(t_game *game, int32_t posX, int32_t posY);
int			update_display_moves(t_game *game, int32_t posX, int32_t posY);

// unused at the end
void		print_2d_arr(char **map_in_arr);

#endif
