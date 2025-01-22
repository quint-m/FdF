/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:52:07 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/16 15:18:41 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scroll_input(double xdelta, double ydelta, void *param)
{
	t_game_data	*game_data;
	float		zoom_factor;

	(void)xdelta;
	game_data = (t_game_data *)param;
	if (ydelta > 0)
		game_data->camera->zoom += 1 * game_data->camera->zoom_factor;
	else
		game_data->camera->zoom -= 1 * game_data->camera->zoom_factor;
}

void	keyboard_input(mlx_key_data_t keydata, void *param)
{
	t_game_data	*game_data;
	float		speed;

	game_data = (t_game_data *)param;
	speed = 10;
	if (keydata.key == MLX_KEY_W)
		game_data->camera->offset.y += 1 * speed;
	else if (keydata.key == MLX_KEY_S)
		game_data->camera->offset.y -= 1 * speed;
	else if (keydata.key == MLX_KEY_A)
		game_data->camera->offset.x += 1 * speed;
	else if (keydata.key == MLX_KEY_D)
		game_data->camera->offset.x -= 1 * speed;
}
