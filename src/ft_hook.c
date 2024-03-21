/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:51:44 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/21 11:54:38 by ajehle           ###   ########.fr       */
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


// int	check_obstacle(t_game *game, int pos_y, int pos_x)
// {
// 	t_borders	a;
// 	t_borders	b;

// 	a.minX = game->player->image->instances[0].x;
// 	a.maxX = game->player->image->instances[0].x + game->player->image->width;
// 	a.minY = game->player->image->instances[0].y;
// 	a.maxY = game->player->image->instances[0].y + game->player->image->height;
// 	b.minX = pos_x;
// 	b.maxX = pos_x + game->exit->image->width;
// 	b.minY = pos_y;
// 	b.maxY = pos_y + game->exit->image->height;
// 	if((a.maxX >= b.minX) && (a.minX <= b.maxX) && (a.maxY >= b.minY) && (a.minY <= b.maxY))
// 	{
// 		return(1);
// 	}
// 	return(0);
// }

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
			printf("%i\n",(game->player->image->instances[0].y - PLAYER_STEP));
			// if(!check_obstacle(game, (game->player->image->instances[0].y - PLAYER_STEP),game->player->image->instances[0].x))
			// {
				game->player->image->instances[0].y -= PLAYER_STEP;
				game->player->moves += 1;
			// }
		}
	}
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
	{
		if ((game->player->image->instances[0].y + PLAYER_STEP <= (int)(game->height - game->player->image->height) - 1))
		{
			printf("%i\n",(game->player->image->instances[0].y + PLAYER_STEP));
			game->player->image->instances[0].y += PLAYER_STEP;
			game->player->moves += 1;
		}
	}
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
	{
		if (game->player->image->instances[0].x - PLAYER_STEP >= PIXEL)
		{
			printf("%i\n",(game->player->image->instances[0].x - PLAYER_STEP));
			game->player->image->instances[0].x -= PLAYER_STEP;
			game->player->moves += 1;
		}
	}
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
	{
		if (game->player->image->instances[0].x + PLAYER_STEP <= (int)(game->width - game->player->image->width) - 1)
		{
			printf("%i\n",(game->player->image->instances[0].x + PLAYER_STEP));
			game->player->image->instances[0].x += PLAYER_STEP;
			game->player->moves += 1;
		}
	}

	// check_enemy(game);
	// check_collect(game);
	// check_exit(game);
	update_display_moves(game, 300, 100);
	update_display_item(game, 400, 100);

}
