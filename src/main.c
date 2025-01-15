/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:06:50 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/15 21:42:48 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*screen;
	t_vec2		p0;
	t_vec2		p1;

	p0.x = 0;
	p0.y = 0;
	p1.x = 100;
	p1.y = 100;

	mlx = create_window(WIDTH, HEIGHT, "FdF");
	screen = create_screen(WIDTH, HEIGHT, mlx);
	draw_wu_line(screen, &p0, &p1);
	mlx_loop(mlx);
	mlx_delete_image(mlx, screen);
	mlx_terminate(mlx);
	mlx = NULL;
	screen = NULL;
	return (0);
}
