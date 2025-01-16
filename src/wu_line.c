/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wu_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:14:02 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/15 21:49:47 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

static void	swap(float *a, float *b)
{
	float	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	determine_points(t_vec2 *p0, t_vec2 *p1)
{
	int	steep;

	steep = abs((int) (p1->y - p0->y)) > abs((int) (p1->x - p0->x));
	if (steep)
	{
		swap(&p0->x, &p0->y);
		swap(&p1->x, &p1->y);
	}
	if (p0->x > p1->x)
	{
		swap(&p0->x, &p1->x);
		swap(&p0->y, &p1->y);
	}
}

static void	put_pixel(mlx_image_t *screen, int x, int y, float brightness)
{
	mlx_put_pixel(screen, x, y, pixel_color(255, 255, 255, 255 * brightness));
}

static void	put_endpoint(mlx_image_t *screen, t_vec2 *point, float gradient, int steep)
{
	float		x_gap;
	float		x_end;
	float		y_end;

	x_end = round(point->x);
	y_end = point->y + gradient * (x_end - point->x);
	x_gap = rfpart(point->x + 0.5);
	if (steep)
	{
		put_pixel(screen, ipart(y_end), (int) x_end, rfpart(y_end) * x_gap);
		put_pixel(screen, ipart(y_end) + 1, (int) x_end, rfpart(y_end) * x_gap);
	}
	else
	{

		put_pixel(screen, (int) x_end, ipart(y_end), rfpart(y_end) * x_gap);
		put_pixel(screen, (int) x_end, ipart(y_end)+ 1, rfpart(y_end) * x_gap);
	}
}

void	draw_wu_line(mlx_image_t *screen, t_vec2 *p0, t_vec2 *p1)
{
	int		steep;
	int		x;
	float	iternary;
	float	dx;
	float	gradient;
	float	dy;

	steep = abs((int) (p1->y - p0->y)) > abs((int) (p1->x - p0->x));
	determine_points(p0, p1);
	dx = p1->x - p0->x;
	dy = p1->y - p0->y;
	if (dx == 0.0f)
		gradient = 1.0;
	else
		gradient = dy / dx;

	iternary = p0->y + gradient * (round(p0->x) - p0->x) + gradient;
	put_endpoint(screen, p0, gradient, steep);
	put_endpoint(screen, p1, gradient, steep);

	x = round(p0->x) + 1;
	while (x < round(p1->x) - 1)
	{
		if (steep)
		{
			put_pixel(screen, ipart(iternary), x, rfpart(iternary));
			put_pixel(screen, ipart(iternary) + 1, x, rfpart(iternary));
		}
		else
		{
			put_pixel(screen, x, ipart(iternary), rfpart(iternary));
			put_pixel(screen, x, ipart(iternary) + 1, rfpart(iternary));
		}
		iternary += gradient;
		x++;
	}
}
