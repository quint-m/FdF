/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:52:42 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/15 21:09:30 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static int	determine_step(int dx, int dy)
{
	if (abs(dx) > abs(dy))
		return (abs(dx));
	else if (abs(dy) > abs(dx))
		return (abs(dy));
	return abs(dx);
}

static void	draw_step(mlx_image_t *screen, t_vec2 *pos, int dx, int dy)
{
	float	x_step;
	float	y_step;
	int		i;
	int		steps;

	steps = determine_step(dx, dy);
	x_step = dx / (float) steps;
	y_step = dy / (float) steps;

	i = 0;
	while (i <= steps)
	{
		mlx_put_pixel(screen, round(pos->x), round(pos->y), 0xffffffff);
		pos->x += x_step;
		pos->y += y_step;
		i++;
	}
}

void	draw_line(mlx_image_t *screen, t_vec2 *p0, t_vec2 *p1)
{
	int	dx;
	int	dy;

	dx = p1->x - p0->x;
	dy = p1->y - p0->y;
	draw_step(screen, p0, dx, dy);
}
