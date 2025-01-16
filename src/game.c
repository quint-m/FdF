/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:05:19 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/16 14:25:38 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_screen(mlx_image_t *image)
{
	unsigned int	i;

	i = 0;
	while (i < image->width * image->height)
	{
		mlx_put_pixel(image, i % image->width, i / image->width, 0x000000ff);
		i++;
	}
}

void	lifecycle(void *param)
{
	t_game_data	*game_data;
	t_vec3		points[16];

	game_data = (t_game_data *)param;

	points[0] = (t_vec3){.x = 0, .y = 0, .z = 0};
	points[1] = (t_vec3){.x = 1, .y = 0, .z = 0};
	points[2] = (t_vec3){.x = 2, .y = 0, .z = 0};

	points[3] = (t_vec3){.x = 0, .y = 1, .z = 0};
	points[4] = (t_vec3){.x = 1, .y = 1, .z = 2};
	points[5] = (t_vec3){.x = 2, .y = 1, .z = 0};

	points[6] = (t_vec3){.x = 0, .y = 2, .z = 0};
	points[7] = (t_vec3){.x = 1, .y = 2, .z = 0};
	points[8] = (t_vec3){.x = 2, .y = 2, .z = 0};
	clear_screen(game_data->screen);
	render_model(game_data, points);
}
