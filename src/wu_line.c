/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wu_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:10:30 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/28 15:22:15 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdint.h>

static int	ft_lerp(int c1, int c2, float p)
{
	return (c1 + p * (c2 - c1));
}

uint32_t	ft_getcolor(int x, t_point s, t_point e, float brightness)
{
	int		r;
	int		g;
	int		b;
	float	percent;

	percent = (float) abs(x - s.x) / abs(e.x - s.x);
	r = ft_lerp((s.color >> 24) & 0xFF, (e.color >> 24) & 0xFF, percent);
	g = ft_lerp((s.color >> 16) & 0xFF, (e.color >> 16) & 0xFF, percent);
	b = ft_lerp((s.color >> 8) & 0xFF, (e.color >> 8) & 0xFF, percent);
	return (r << 24 | g << 16 | b << 8 | (int) (255 * brightness));
}

void	ft_putpixel(int xp, int yp, uint32_t color, t_env *env)
{
	if (xp >= 0 && xp < env->w_width && yp >= 0 && yp < env->w_height)
		mlx_put_pixel(env->image, xp, yp, color);
}

static void	ft_draw_line_loop(t_point s, t_point e, float gradient, t_env *env)
{
	float	inter_y;
	int		x;

	inter_y = (float)s.y;
	x = s.x;
	while (x <= e.x)
	{
		if (env->steep)
		{
			ft_putpixel(ft_ipart(inter_y), x, ft_getcolor(x, s, e, ft_rfpart(inter_y)), env);
			ft_putpixel(ft_ipart(inter_y) + 1, x, ft_getcolor(x, s, e, ft_rfpart(inter_y)), env);
		}
		else
		{
			ft_putpixel(x, ft_ipart(inter_y), ft_getcolor(x, s, e, ft_rfpart(inter_y)), env);
			ft_putpixel(x, ft_ipart(inter_y) + 1, ft_getcolor(x, s, e, ft_rfpart(inter_y)), env);
		}
		inter_y += gradient;
		x++;
	}
}

void	ft_draw_line(t_point s, t_point e, t_env *env)
{
	float	dy;
	float	dx;
	float	gradient;

	if ((s.x < 0 || s.x >= env->w_width || s.y < 0 || s.y >= env->w_height)
		&& (e.x < 0 || e.x >= env->w_width || e.y < 0 || e.y >= env->w_height))
		return ;
	env->steep = abs(e.y - s.y) > abs(e.x - s.x);
	if (env->steep)
	{
		ft_swap(&s.x, &s.y);
		ft_swap(&e.x, &e.y);
	}
	if (s.x > e.x)
	{
		ft_swap(&s.x, &e.x);
		ft_swap(&s.y, &e.y);
	}
	dx = (float)(e.x - s.x);
	dy = (float)(e.y - s.y);
	gradient = dy / dx;
	if (dx == 0.0f)
		gradient = 1.0f;
	ft_draw_line_loop(s, e, gradient, env);
}
