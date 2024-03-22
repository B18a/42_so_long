/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:51:44 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/22 09:47:49 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	update_display_item(t_game *game, int32_t posX, int32_t posY)
{
	char *str;

	str = ft_itoa(game->player->item);
	mlx_delete_image(game->game_window, game->player->item_image);
	game->player->item_image = mlx_put_string(game->game_window,str, posX, posY);
	if(str)
		free(str);
}
void	update_display_moves(t_game *game, int32_t posX, int32_t posY)
{
	char *str;

	str = ft_itoa(game->player->moves);
	mlx_delete_image(game->game_window, game->player->move_image);
	game->player->move_image = mlx_put_string(game->game_window,str, posX, posY);
	if(str)
		free(str);
}




int check_up(t_game *game)
{
	if(game->map_as_arr[(game->player->image->instances[0].y) / PIXEL - 1][(game->player->image->instances[0].x) / PIXEL] != '1')
		return(0);
	return(1);
}
int check_down(t_game *game)
{
	if(game->map_as_arr[(game->player->image->instances[0].y) / PIXEL + 1][(game->player->image->instances[0].x) / PIXEL] != '1')
		return(0);
	return(1);
}
int check_left(t_game *game)
{
	if(game->map_as_arr[(game->player->image->instances[0].y) / PIXEL][(game->player->image->instances[0].x) / PIXEL - 1] != '1')
		return(0);
	return(1);
}
int check_right(t_game *game)
{
	if(game->map_as_arr[(game->player->image->instances[0].y) / PIXEL][(game->player->image->instances[0].x) / PIXEL + 1] != '1')
		return(0);
	return(1);
}


void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(game->game_window);
	}

	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS) // One Step per Press
	{
		if ((game->player->image->instances[0].y - PLAYER_STEP >= PIXEL) )
		{
			// printf("pos[%i][%i]\n",(game->player->image->instances[0].y - PLAYER_STEP),(game->player->image->instances[0].x));
			if(!check_up(game))
			{
				game->player->image->instances[0].y -= PLAYER_STEP;
				game->player->moves += 1;
			}
		}
	}
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
	{
		if ((game->player->image->instances[0].y + PLAYER_STEP <= (int)(game->height - game->player->image->height) - 1))
		{
			// printf("pos[%i][%i]\n",(game->player->image->instances[0].y + PLAYER_STEP),(game->player->image->instances[0].x));
			if(!check_down(game))
			{
				game->player->image->instances[0].y += PLAYER_STEP;
				game->player->moves += 1;
			}
		}
	}
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
	{
		if (game->player->image->instances[0].x - PLAYER_STEP >= PIXEL)
		{
			// printf("pos[%i][%i]\n",(game->player->image->instances[0].y),(game->player->image->instances[0].x - PLAYER_STEP));
			if(!check_left(game))
			{
				game->player->image->instances[0].x -= PLAYER_STEP;
				game->player->moves += 1;
			}
		}
	}
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
	{
		if (game->player->image->instances[0].x + PLAYER_STEP <= (int)(game->width - game->player->image->width) - 1)
		{
			// printf("pos[%i][%i]\n",(game->player->image->instances[0].y),(game->player->image->instances[0].x + PLAYER_STEP));
			if(!check_right(game))
			{
				game->player->image->instances[0].x += PLAYER_STEP;
				game->player->moves += 1;
			}
		}
	}

	// check_enemy(game);
	// check_collect(game);
	// check_exit(game);
	update_display_moves(game, 10, 100);
	update_display_item(game, 50, 100);

}
