/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:09:33 by ajehle            #+#    #+#             */
/*   Updated: 2024/02/17 12:15:24 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"




#define WIDTH	500
#define HEIGHT	500

static void ft_hook(void* param)
{
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
}

// void	ft_key_hook(mlx_key_data_t *key, void *data)
// {

// }

int	ft_exit_player(t_player *player)
{
	if(player)
		free(player);
	return(1);
}

int	ft_exit_game(t_game *game)
{
	if(game->game_window)
		free(game->game_window);
	if(game->game_image)
		free(game->game_image);
	if(game->player)
		free(game->player);
	if(game)
		free(game);
	return(1);
}

void	call_exit(t_game *game)
{
	ft_exit_player(game->player);
	ft_exit_game(game);
}

t_player *ft_initialize_player()
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	player->x_pos_player = 300;
	player->y_pos_player = 300;


	return (player);
}

t_game	*ft_initialize_game()
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if(!game)
		return(ft_exit_game(game), NULL);
/************************************************/

	game->game_window = malloc(sizeof(mlx_t));
	if(!game->game_window)
		return(ft_exit_game(game), NULL);

	game->game_window = mlx_init(WIDTH, HEIGHT, "test", false);
	if (!game->game_window)
		return(call_exit(game), NULL);
/************************************************/
	game->game_image = malloc(sizeof(mlx_image_t));
	if(!game->game_image)
		return(ft_exit_game(game), NULL);
	game->game_image = mlx_new_image(game->game_window, WIDTH, HEIGHT);
		if (!game->game_image)
			return(call_exit(game), NULL);
	if (mlx_image_to_window(game->game_window, game->game_image, 100, 0) == -1)
			return(call_exit(game), NULL);
/************************************************/

	game->player = malloc(sizeof(t_player));
	if(!game->player)
		return(ft_exit_game(game), NULL);
	return (game);
}







int	main(void)
{
/************************************************/
/****************Initialize Player**************/
/************************************************/
	t_player	*player;
	player = ft_initialize_player();
	if(!player)
		return(ft_exit_player(player));


/************************************************/
/****************Initialize Game**************/
/************************************************/
	t_game	*game;
	game = ft_initialize_game();
	if (!game)
		return(call_exit(game), 0);

/************************************************/
/****************Draw Line**************/
/************************************************/
	int x;
	x = 0;
	while (x < 300)
	{
		x++;
		mlx_put_pixel(game->game_image, x, 100, 0xFF00F0FF);
	}

	player->texture = mlx_load_png("./assets/Link.png");
	player->image = mlx_texture_to_image(game->game_window, player->texture);

	mlx_image_to_window(game->game_window, player->image, player->x_pos_player, player->y_pos_player);
	//*******************************************************

	// mlx_key_hook(window, ft_key_hook, player);
	mlx_loop_hook(game->game_window, ft_hook, game->game_window);

	mlx_loop(game->game_window);
	// mlx_terminate(window);

	return (0);
}