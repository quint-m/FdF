/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:05:19 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/16 18:41:58 by qmennen          ###   ########.fr       */
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
	t_map		map;

	map = parse_map("./maps/test.map");
	game_data = (t_game_data *)param;
	game_data->map = &map;
	clear_screen(game_data->screen);
	render_model(game_data, game_data->map);
}
