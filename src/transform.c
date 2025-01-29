/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:41:25 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/28 15:25:11 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_rotate_x(int *y, int *z, double x_angle)
{
	int	prev_y;

	prev_y = *y;
	*y = prev_y * cos(x_angle) + *z * sin(x_angle);
	*z = prev_y * -sin(x_angle) + *z * cos(x_angle);
}

static void	ft_rotate_y(int *x, int *z, double y_angle)
{
	int	prev_x;

	prev_x = *x;
	*x = prev_x * cos(y_angle) + *z * sin(y_angle);
	*z = prev_x * -sin(y_angle) + *z * cos(y_angle);
}

static void	ft_rotate_z(int *x, int *y, double z_angle)
{
	t_point	prev;

	prev.x = *x;
	prev.y = *y;
	*x = prev.x * cos(z_angle) - prev.y * sin(z_angle);
	*y = prev.x * sin(z_angle) + prev.y * cos(z_angle);
}

t_point	project(int x, int y, t_env *env)
{
	t_point	point;

	point.z = env->map->grid[x + y * env->map->width].z;
	point.color = env->map->grid[x + y * env->map->width].color;
	point.x = x * env->cam->zoom;
	point.y = y * env->cam->zoom;
	point.z *= env->cam->zoom;
	if (point.color == 0)
		point.color = ft_get_default_color(x, y, env);
	point.x -= (env->map->width * env->cam->zoom) / 2;
	point.y -= (env->map->height * env->cam->zoom) / 2;
	ft_rotate_x(&point.y, &point.z, env->cam->x_angle);
	ft_rotate_y(&point.x, &point.z,  env->cam->y_angle);
	ft_rotate_z(&point.x, &point.y, env->cam->z_angle); 
	point.x += env->w_width / 2 + env->cam->x_offset;
	point.y += (env->w_height + env->map->height / 2 * env->cam->zoom) / 2
		+ env->cam->y_offset;
	return (point);
}
