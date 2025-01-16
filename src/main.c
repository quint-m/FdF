/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:06:50 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/16 17:28:50 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static t_camera	*init_cam()
{
	t_camera	*cam;

	cam = malloc(sizeof(t_camera));
	if (!cam)
		program_exit("Failed to initialize camera\n");
	cam->zoom_factor = 10;
	cam->zoom = 64;
	cam->offset = (t_vec2){.x = 0, .y = 0};
	return (cam);
}

int	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*screen;
	t_camera	*camera;
	t_game_data	game_data;

//	parse_map("./maps/test.map");
	mlx = create_window(WIDTH, HEIGHT, "FdF");
	screen = create_screen(WIDTH, HEIGHT, mlx);
	camera = init_cam();
	game_data.mlx = mlx;
	game_data.screen = screen;
	game_data.camera = camera;
	mlx_loop_hook(mlx, lifecycle, &game_data);
	mlx_scroll_hook(mlx, scroll_input, &game_data);
	mlx_key_hook(mlx, keyboard_input, &game_data);
	mlx_loop(mlx);
	mlx_delete_image(mlx, screen);
	mlx_terminate(mlx);
	free(camera);
	return (0);
}
