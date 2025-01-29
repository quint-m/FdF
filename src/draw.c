/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:34:36 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/29 18:05:20 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void ft_clear(t_env *env)
{
	int i;

	i = 0;
	while (i < env->w_width * env->w_height)
	{
		mlx_put_pixel(env->image, i % env->w_width, i / env->w_width, 0x000000FF);
		i++;
	}
}

void ft_draw(t_env *env)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	while (i < env->map->width * env->map->height)
	{
		x = i % env->map->width;
		y = i / env->map->width;
		if (x != env->map->width - 1)
		{
			ft_draw_line(project(env->map->grid[x + y * env->map->width].x, env->map->grid[x + y * env->map->width].y, env), project(env->map->grid[x + 1 + y * env->map->width].x, env->map->grid[x + 1 + y * env->map->width].y, env), env);
		}
		if (y != env->map->height - 1)
		{
			ft_draw_line(project(env->map->grid[x + y * env->map->width].x, env->map->grid[x + y * env->map->width].y, env), project(env->map->grid[x + (y + 1) * env->map->width].x, env->map->grid[x+ (y + 1) * env->map->width].y, env), env);
		}
		i++;
	}
}
