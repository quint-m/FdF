/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:48:19 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/28 15:35:24 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "fdf.h"

static t_env	*ft_init(int w, int h)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (!env)
		ft_program_error("failed to initialize ENV", 1);
	env->mlx = mlx_init(w, h, "FdF", true);
	if (!env->mlx)
		ft_program_error(mlx_strerror(mlx_errno), 0);
	env->image = mlx_new_image(env->mlx, w, h);
	if (!env->image || (mlx_image_to_window(env->mlx, env->image, 0, 0) < 0)) 
		ft_program_error(mlx_strerror(mlx_errno), 0);
	env->map = NULL;
	env->cam = NULL;
	env->w_width = w;
	env->w_height = h;
	return (env);
}

static t_map	*ft_init_map()
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		ft_program_error("malloc for map failed", 1);
	map->width = 0;
	map->height = 0;
	map->grid = NULL;
	map->z_max = 0;
	map->z_min = 0;
	return (map);
}

static t_cam	*ft_init_cam()
{
	t_cam	*cam;

	cam = malloc(sizeof(t_cam));
	if (!cam)
		ft_program_error("malloc for camera failed", 1);
	cam->x_offset = 0;
	cam->y_offset = 0;
	cam->x_angle = -0.615472907f;
	cam->y_angle = -0.7853981633f;
	cam->z_angle = 0.615472907f;
	cam->zoom = 4;
	return (cam);
}

static void	ft_loop(void *param)
{
	t_env		*env;

	env = (t_env *)param;
	ft_clear(env);
	ft_draw(env);
}

int	main(int argc, char **argv)
{
	t_env	*env;

	if (argc != 2)
		ft_program_error("Usage ./FDF <map_file.fdf>", 0);
	env = ft_init(1280, 720);
	env->map = ft_init_map();
	env->cam = ft_init_cam();
	if (! ft_validate_map(argv[1], env->map))
		ft_program_error("failed parsing map file", 0);
	mlx_key_hook(env->mlx, ft_keypress, env);
	mlx_resize_hook(env->mlx, ft_resize, env);
	mlx_close_hook(env->mlx, ft_close_window, env);
	mlx_loop_hook(env->mlx, ft_loop, env);
	mlx_scroll_hook(env->mlx, ft_scroll, env);

	mlx_loop(env->mlx);
	return (0);
}
