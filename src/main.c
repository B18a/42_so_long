/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:09:33 by ajehle            #+#    #+#             */
/*   Updated: 2024/02/17 10:27:15 by ajehle           ###   ########.fr       */
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

t_player *ft_initialize_player()
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	player->x_pos_player = 300;
	player->y_pos_player = 300;
	

	return (player);
}

int	ft_exit_player(t_player *player, mlx_t *window, mlx_image_t *image)
{
	if(player)
		free(player);
	if(window)
		free(window);
	if(image)
		free(image);
	return(1);
}

int	ft_exit_game(t_game *game)
{
	if(game->game_image)
		free(game->game_image);
	if(game->game_window)
		free(game->game_window);
	if(game)
		free(game);
	return(1);
}


t_game	*ft_initialize_game()
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if(!game)
		return(ft_exit_game(game), NULL);
	game->game_window = malloc(sizeof(mlx_t));
	if(!game->game_window)
		return(ft_exit_game(game), NULL);
	game->game_image = malloc(sizeof(mlx_image_t));
	if(!game->game_image)
		return(ft_exit_game(game), NULL);
	return (game);
}

int	main(void)
{
	mlx_t	*window;
	mlx_image_t	*image;

	t_player	*player;
	player = ft_initialize_player();
	if(!player)
		return(ft_exit_player(player, NULL, NULL));

	t_game	*game;
	game = ft_initialize_game();
	if (!game)
		return(ft_exit_player(player, NULL, NULL));


	window = mlx_init(WIDTH, HEIGHT, "test", false);
	if (!window)
		return(ft_exit_player(player, window, NULL));

	image = mlx_new_image(window, WIDTH, HEIGHT);
	if (!image)
		return (ft_exit_player(player, window, image));
	if (mlx_image_to_window(window, image, 100, 0) == -1)
		return (ft_exit_player(player, window, image));



	int x;
	x = 0;
	while (x < 300)
	{
		x++;
		mlx_put_pixel(image, x, 100, 0xFF00F0FF);
	}

	player->texture = mlx_load_png("./assets/Link.png");
	player->image = mlx_texture_to_image(window, player->texture);

	mlx_image_to_window(window, player->image, player->x_pos_player, player->y_pos_player);
	//*******************************************************

	// mlx_key_hook(window, ft_key_hook, player);
	mlx_loop_hook(window, ft_hook, window);

	mlx_loop(window);
	// mlx_terminate(window);

	return (0);
}