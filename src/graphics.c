/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:19:09 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/16 16:04:53 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <stdio.h>

static void	transform_model(t_vec3 **vertices, int vertex_count)
{
	int	i;

	i = 0;
	while (i < vertex_count)
	{
		isometric(vertices[i]);
		i++;
	}
}

static void	render_horizontal_edges(mlx_image_t *screen, t_camera *camera, t_map *map)
{
	t_vec2	r_point;
	t_vec2	p0;
	t_vec2	p1;
	int		idx;

	r_point.y = 0;
	while (r_point.y < map->height)
	{
		r_point.x = 0;
		while (r_point.x < map->width - 1)
		{
			idx = r_point.y * map->width + r_point.x;
			p0.x = camera->offset.x + (WIDTH - map->map[idx]->x * camera->zoom) / 2;
			p0.y = camera->offset.y + (HEIGHT + map->map[idx]->y * camera->zoom) / 2;
			p1.x = camera->offset.x + (WIDTH - map->map[idx + 1]->x * camera->zoom) / 2;
			p1.y = camera->offset.y + (HEIGHT + map->map[idx + 1]->y * camera->zoom) / 2;
			//draw_wu_line(screen, &p0, &p1);
			draw_line(screen, &p0, &p1);
			r_point.x++;
		}
		r_point.y++;
	}
}

static void	render_vertical_edges(mlx_image_t *screen, t_camera *camera, t_map *map)
{
	t_vec2	r_point;
	t_vec2	p0;
	t_vec2	p1;
	int		idx;

	r_point.y = 0;
	while (r_point.y < map->height - 1)
	{
		r_point.x = 0;
		while (r_point.x < map->width)
		{
			idx = r_point.y * map->width + r_point.x;
			p0.x = camera->offset.x +(WIDTH - map->map[idx]->x * camera->zoom) / 2;
			p0.y = camera->offset.y +(HEIGHT + map->map[idx]->y * camera->zoom) / 2;
			p1.x = camera->offset.x +(WIDTH - map->map[idx + map->width]->x * camera->zoom) / 2;
			p1.y = camera->offset.y + (HEIGHT + map->map[idx + map->width]->y * camera->zoom) / 2;
			//draw_wu_line(screen, &p0, &p1);
			draw_line(screen, &p0, &p1);
			r_point.x++;
		}
		r_point.y++;
	}
}

void		render_model(t_game_data *game_data, t_map *map)
{
	int			x;
	int			y;
	t_vec2		p0;
	t_vec2		p1;
	t_camera	*camera;
	
	camera = game_data->camera;
	//transform_model(map->map, vertex_count(map->map));
	render_horizontal_edges(game_data->screen, game_data->camera, map);
	render_vertical_edges(game_data->screen, game_data->camera, map);
}

mlx_image_t	*create_screen(int width, int height, mlx_t *window_h)
{
	mlx_image_t	*screen;

	screen = mlx_new_image(window_h, width, height);
	if (!screen || (mlx_image_to_window(window_h, screen, 0, 0) < 0))
		mlx_exit();
	return (screen);
}
