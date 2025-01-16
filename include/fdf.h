/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:52:52 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/16 15:15:18 by qmennen          ###   ########.fr       */
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

typedef struct vec3
{
	float x;
	float y;
	float z;
}	t_vec3;

typedef struct camera
{
	float	zoom_factor;
	float	zoom;
}	t_camera;

typedef struct game_data
{
	mlx_t		*mlx;
	mlx_image_t	*screen;
	t_camera	*camera;
}	t_game_data;

/*
 * Game
 */
void		lifecycle(void *param);
/*
 * Graphics
 */
void		render_model(t_game_data *game_data, t_vec3 *points);
int			pixel_color(int r, int g, int b, int a);
void		draw_line(mlx_image_t *screen, t_vec2 *p0, t_vec2 *p1);
void		isometric(t_vec3 *point);
/*
 * Wu line
 */
void	draw_wu_line(mlx_image_t *screen, t_vec2 *p0, t_vec2 *p1);
float	rfpart(float x);
float	fpart(float x);
int		ipart(float x);
/*
 * Helpers
 */
mlx_t		*create_window(int width, int height, const char *title);
mlx_image_t	*create_screen(int width, int height, mlx_t *window_h);
void		p_exit(void);
/*
 * Camera
 */
void	scroll_input(double xdelta, double ydelta, void *param);
#endif
