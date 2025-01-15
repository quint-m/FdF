/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:52:52 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/15 21:40:19 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIDTH 1280
# define HEIGHT 720
# include <MLX42/MLX42.h>
# include <math.h>
# include <stdlib.h>
# include "libft.h"

typedef struct vec2
{
	float	x;
	float	y;
}	t_vec2;

int			pixel_color(int r, int g, int b, int a);
void		draw_line(mlx_image_t *screen, t_vec2 *p0, t_vec2 *p1);
void		draw_wu_line(mlx_image_t *screen, t_vec2 *p0, t_vec2 *p1);
mlx_t		*create_window(int width, int height, const char *title);
mlx_image_t	*create_screen(int width, int height, mlx_t *window_h);
void		p_exit(void);
/**
	*
	*/

float	rfpart(float x);
float	fpart(float x);
int		ipart(float x);
#endif
