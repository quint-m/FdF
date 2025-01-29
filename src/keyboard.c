/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:20:33 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/28 13:25:38 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <sys/types.h>

void	ft_translate(key_t k_code, t_env *env)
{
	int	cam_speed;

	cam_speed = 3;
	if (k_code == MLX_KEY_W)
		env->cam->y_offset -= cam_speed;;
	if (k_code == MLX_KEY_S)
		env->cam->y_offset += cam_speed;
	if (k_code == MLX_KEY_A)
		env->cam->x_offset -= cam_speed;;
	if (k_code == MLX_KEY_D)
		env->cam->x_offset += cam_speed;
}

void	ft_rotate(key_t k_code, t_env *env)
{
	int	rot_speed;

	rot_speed = 2;
	if (k_code == MLX_KEY_UP)
		env->cam->y_angle += 0.1f;
	if (k_code == MLX_KEY_DOWN)
		env->cam->y_angle -= 0.1f;
	if (k_code == MLX_KEY_LEFT)
		env->cam->x_angle -= 0.1f;
	if (k_code == MLX_KEY_RIGHT)
		env->cam->x_angle += 0.1f;
}
