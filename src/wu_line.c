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
#include <stdio.h>

static void	swap(float *a, float *b)
{
	float	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	put_pixel(mlx_image_t *screen, int x, int y, float brightness)
{
	mlx_put_pixel(screen, x, y, pixel_color(255, 255, 255, 255 * brightness));
}

void	draw_wu_line(mlx_image_t *screen, t_vec2 *p0, t_vec2 *p1)
{
	int			steep;
	int			x;
	int			xpxl1;
	int			ypxl1;
	int			xpxl2;
	int			ypxl2;
	float		x_end;
	float		y_end;
	float		iternary;
	float	x_gap;
	float	dx;
	float	gradient;
	float	dy;

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
	dx = p1->x - p0->x;
	dy = p1->y - p0->y;
	if (dx == 0.0f)
		gradient = 1.0;
	else
		gradient = dy / dx;
	x_end = round(p0->x);
	y_end = p0->y + gradient * (x_end - p0->x);
	x_gap = rfpart(p0->x + 0.5);
	xpxl1 = x_end;
	ypxl1 = ipart(y_end);
	if (steep)
	{
		put_pixel(screen, ypxl1, xpxl1, rfpart(y_end) * x_gap);
		put_pixel(screen, ypxl1 + 1, xpxl1, rfpart(y_end) * x_gap);
	}
	else
	{

		put_pixel(screen, xpxl1, ypxl1, rfpart(y_end) * x_gap);
		put_pixel(screen, xpxl1, ypxl1 + 1, rfpart(y_end) * x_gap);
	}

	iternary = y_end + gradient;
	x_end = round(p1->x);
	y_end = p1->y + gradient * (x_end - p1->x);
	x_gap = rfpart(p1->x + 0.5);
	xpxl2 = x_end;
	ypxl2 = ipart(y_end);
	if (steep)
	{
//		mlx_put_pixel(screen, ypxl2, xpxl2, pixel_color(255, 255, 255, 255 * (rfpart(y_end) * x_gap)));
//		mlx_put_pixel(screen, ypxl2 + 1, xpxl2, pixel_color(255, 255, 255, 255 * (fpart(y_end) * x_gap)));
		put_pixel(screen, ypxl2, xpxl2, rfpart(y_end) * x_gap);
		put_pixel(screen, ypxl2 + 1, xpxl2, rfpart(y_end) * x_gap);
	}
	else
	{
//		mlx_put_pixel(screen, xpxl2, ypxl2, pixel_color(255, 255, 255, 255 * (rfpart(y_end) * x_gap)));
//		mlx_put_pixel(screen, xpxl2, ypxl2 + 1, pixel_color(255, 255, 255, 255 * (rfpart(y_end) * x_gap)));
		put_pixel(screen, xpxl2, ypxl2, rfpart(y_end) * x_gap);
		put_pixel(screen, xpxl2, ypxl2 + 1, rfpart(y_end) * x_gap);
	}
	if (steep)
	{
		x = xpxl1 + 1;
		while (x < xpxl2 - 1)
		{
//			mlx_put_pixel(screen, ipart(iternary), x, rfpart(iternary) * 255);
//			mlx_put_pixel(screen, ipart(iternary) + 1, x, rfpart(iternary) * 255);
			put_pixel(screen, ipart(iternary), x, rfpart(iternary));
			put_pixel(screen, ipart(iternary) + 1, x, rfpart(iternary));
			iternary += gradient;
			x++;
		}
	}
	else
	{
		x = xpxl1 + 1;
		while (x < xpxl2 - 1)
		{
//			mlx_put_pixel(screen, x, ipart(iternary), rfpart(iternary) * 255);
//			mlx_put_pixel(screen, x, ipart(iternary) + 1, rfpart(iternary) * 255);
			put_pixel(screen, x, ipart(iternary), rfpart(iternary));
			put_pixel(screen, x, ipart(iternary) + 1, rfpart(iternary));
			iternary += gradient;
			x++;
		}

	}
}
