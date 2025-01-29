/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:57:14 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/28 15:33:23 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_keypress(mlx_key_data_t keydata, void *param)
{
	t_env	*env;

	env = (t_env *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		ft_close_window(param);
	else if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_RIGHT
			|| keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_DOWN)
			ft_rotate(keydata.key, env);
	else if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_S
			|| keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_D)
		ft_translate(keydata.key, env);
}

void	ft_scroll(double xdelta, double ydelta, void *param)
{
	t_env	*env;

	(void)xdelta;
	env = (t_env *)param;
	if (ydelta < 0)
		env->cam->zoom--;
	else if (ydelta > 0)
		env->cam->zoom++;
}

void	ft_resize(int width, int height, void *param)
{
	t_env	*env;

	env = (t_env *)param;
	mlx_resize_image(env->image, width, height);
	env->w_width = width;
	env->w_height = height;
}

void	ft_close_window(void *param)
{
	int	i;
	int	j;
	t_env	*env;

	env = (t_env *)param;
	// j = -1;
	// while (++j < env->map->height)
	// {
	// 	i = -1;
	// 	while (++i < env->map->width)
	// 		free(env->map->grid[j][i]);
	// 	free(env->map->grid[j]);
	// }
	mlx_close_window(env->mlx);
	mlx_delete_image(env->mlx, env->image);
	free(env->map->grid);
	free(env->map);
	free(env->cam);
	free(env);
}
