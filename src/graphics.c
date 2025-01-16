/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:19:09 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/16 15:15:48 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	transform_model(t_vec3 *vertices, int vertex_count)
{
	int	i;

	i = 0;
	while (i < vertex_count)
	{
		isometric(&vertices[i]);
		i++;
	}
}

static void	render_horizontal_edges(t_game_data *game_data, t_vec3 *points)
{
	t_vec2	r_point;
	t_vec2	p0;
	t_vec2	p1;
	int		idx;

	r_point.y = 0;
	while (r_point.y < 3)
	{
		r_point.x = 0;
		while (r_point.x < 2)
		{
			idx = r_point.y * 3 + r_point.x;
			p0.x = (WIDTH - points[idx].x * game_data->camera->zoom) / 2;
			p0.y = (HEIGHT + points[idx].y * game_data->camera->zoom) / 2;
			p1.x = (WIDTH - points[idx + 1].x * game_data->camera->zoom) / 2;
			p1.y = (HEIGHT + points[idx + 1].y * game_data->camera->zoom) / 2;
			draw_wu_line(game_data->screen, &p0, &p1);
			r_point.x++;
		}
		r_point.y++;
	}
}

static void	render_vertical_edges(t_game_data *game_data, t_vec3 *points)
{
	t_vec2	r_point;
	t_vec2	p0;
	t_vec2	p1;
	int		idx;

	r_point.y = 0;
	while (r_point.y < 2)
	{
		r_point.x = 0;
		while (r_point.x < 3)
		{
			idx = r_point.y * 3 + r_point.x;
			p0.x = (WIDTH - points[idx].x * game_data->camera->zoom) / 2;
			p0.y = (HEIGHT + points[idx].y * game_data->camera->zoom) / 2;
			p1.x = (WIDTH - points[idx + 3].x * game_data->camera->zoom) / 2;
			p1.y = (HEIGHT + points[idx + 3].y * game_data->camera->zoom) / 2;
			draw_wu_line(game_data->screen, &p0, &p1);
			r_point.x++;
		}
		r_point.y++;
	}
}

void		render_model(t_game_data *game_data, t_vec3 *points)
{
	int		x;
	int		y;
	int		i;
	t_vec2	p0;
	t_vec2	p1;

	transform_model(points, 3 * 3);
	render_horizontal_edges(game_data, points);
	render_vertical_edges(game_data, points);
}

mlx_image_t	*create_screen(int width, int height, mlx_t *window_h)
{
	mlx_image_t	*screen;

	screen = mlx_new_image(window_h, width, height);
	if (!screen || (mlx_image_to_window(window_h, screen, 0, 0) < 0))
		p_exit();
	return (screen);
}
