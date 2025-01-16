/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:06:50 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/16 14:10:21 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	scroll_hook(double xdelta, double ydelta, void *param)
{
	t_game_data	*game_data;
	float		zoom_factor;

	(void)xdelta;
	zoom_factor = 5;
	game_data = (t_game_data *)param;
	if (ydelta > 0)
		game_data->zoom+=1 * zoom_factor;
	else
		game_data->zoom-=1 * zoom_factor;
}

int	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*screen;
	t_game_data	game_data;

	mlx = create_window(WIDTH, HEIGHT, "FdF");
	screen = create_screen(WIDTH, HEIGHT, mlx);
	game_data.mlx = mlx;
	game_data.screen = screen;
	game_data.zoom = 64;
	mlx_loop_hook(mlx, lifecycle, &game_data);
	mlx_scroll_hook(mlx, scroll_hook, &game_data);
	mlx_loop(mlx);
	mlx_delete_image(mlx, screen);
	mlx_terminate(mlx);
	return (0);
}
