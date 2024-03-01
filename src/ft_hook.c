/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:51:44 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/01 09:56:01 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

// static void ft_hook(void* param)
// {
// 	mlx_t	*mlx = param;
// 	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
// 		mlx_close_window(param);
// }

void ft_hook(void* param)
{
	mlx_t	*mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);

}
