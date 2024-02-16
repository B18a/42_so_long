/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreasjehle <andreasjehle@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:09:33 by ajehle            #+#    #+#             */
/*   Updated: 2024/02/16 20:28:13 by andreasjehl      ###   ########.fr       */
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


int	main(void)
{
	mlx_t	*window;
	mlx_image_t	*image;
	int x;

	x = 0;

	window = mlx_init(WIDTH, HEIGHT, "test", false);
	if (!window)
		return(1);

	image = mlx_new_image(window, WIDTH, HEIGHT);
	if (!image)
		return (1);
	if (mlx_image_to_window(window, image, 100, 0) == -1)
		return (1);

	while (x < 300)
	{
		x++;
		mlx_put_pixel(image, x, 100, 0xFF00F0FF);
	}

	//This part here is to display a picture on the scree
	int x_pos_player = 100;
	int y_pos_player = 100;
	mlx_texture_t* link;
	link = mlx_load_png("./assets/Link.png");

	mlx_image_t* link_img;
	link_img = mlx_texture_to_image(window, link);

	mlx_image_to_window(window, link_img, x_pos_player, y_pos_player);
	//*******************************************************
	
	mlx_loop_hook(window, ft_hook, window);

	
	mlx_loop(window);
	// mlx_terminate(window);

	return (0);
}