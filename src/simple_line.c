/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:02:13 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/29 18:05:01 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line_low(t_env *env, t_point start, t_point end)
{
	int			delta;
	int			yi;
	t_point	current;
	t_point	delta_point;

	delta_point.x = end.x - start.x;
	delta_point.y = abs(end.y - start.y);
	yi = 1;
	if (end.y - start.y < 0)
		yi = -1;
	delta = 2 * delta_point.y - delta_point.x;
	current = start;
	while (current.x <= end.x)
	{
		current.color = 0xffffff;
		ft_putpixel(current.x, current.y, current.color, env);
		if (delta > 0)
		{
			current.y += yi;
			delta -= 2 * delta_point.x;
		}
		delta += 2 * delta_point.y;
		current.x++;
	}
}

void	draw_line_high(t_env *env, t_point start, t_point end)
{
	int			delta;
	int			xi;
	t_point	current;
	t_point	delta_point;

	delta_point.x = abs(end.x - start.x);
	delta_point.y = end.y - start.y;
	xi = 1;
	if (end.x - start.x < 0)
		xi = -1;
	delta = 2 * delta_point.x - delta_point.y;
	current = start;
	while (current.y <= end.y)
	{
		current.color = 0xffffffff;
		ft_putpixel(current.x, current.y, current.color, env);
		if (delta > 0)
		{
			current.x += xi;
			delta -= 2 * delta_point.y;
		}
		delta += 2 * delta_point.x;
		current.y++;
	}
}

void	draw_line(t_point start, t_point end, t_env *env)
{
	if ((start.x < 0 || start.x >= (int) env->image->width
			|| start.y < 0 || start.y >= (int) env->image->height)
		&& (end.x < 0 || end.x >= (int) env->image->width
			|| end.y < 0 || end.y >= (int) env->image->height))
		return ;
	if (abs(end.y - start.y) < abs(end.x - start.x))
	{
		if (start.x > end.x)
			draw_line_low(env, end, start);
		else
			draw_line_low(env, start, end);
	}
	else
	{
		if (start.y > end.y)
			draw_line_high(env, end, start);
		else
			draw_line_high(env, start, end);
	}
}
