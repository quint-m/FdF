/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:19:09 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/15 20:52:55 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <stdlib.h>
#include <math.h>

int	pixel_color(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}



mlx_image_t	*create_screen(int width, int height, mlx_t *window_h)
{
	mlx_image_t	*screen;

	screen = mlx_new_image(window_h, width, height);
	if (!screen || (mlx_image_to_window(window_h, screen, 0, 0) < 0))
		p_exit();
	return (screen);
}
