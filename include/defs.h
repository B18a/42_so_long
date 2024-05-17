/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:10:55 by ajehle            #+#    #+#             */
/*   Updated: 2024/04/19 13:59:00 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H

# include "so_long.h"

# define PIXEL 32
# define PLAYER_STEP 32

# define MOVES_POS_X PIXEL
# define MOVES_POS_Y 0

# define ITEM_POS_X 0
# define ITEM_POS_Y 0

# define FRAME 20

# define NAME_WINDOW "SO_LONG"
# define PATH_PLAYER "./assets/32x32/knight.png"
# define PATH_PLAYER1 "./assets/32x32/knight1.png"
# define PATH_PLAYER2 "./assets/32x32/knight2.png"
# define PATH_FLOOR "./assets/32x32/floor_1.png"
# define PATH_OBSTACLE "./assets/32x32/wall_1.png"
# define PATH_EXIT_CLOSED "./assets/32x32/floor_2.png"
# define PATH_EXIT_OPEN "./assets/32x32/stair_nextlevel.png"
# define PATH_ITEM "./assets/32x32/key_silver.png"
# define PATH_ENEMY "./assets/32x32/ghost.png"

#endif
