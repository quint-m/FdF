/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:52:07 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/16 15:16:01 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scroll_input(double xdelta, double ydelta, void *param)
{
	t_game_data	*game_data;
	float		zoom_factor;

	(void)xdelta;
	game_data = (t_game_data *)param;
	if (ydelta > 0)
		game_data->camera->zoom += 1 * game_data->camera->zoom_factor;
	else
		game_data->camera->zoom -= 1 * game_data->camera->zoom_factor;
}

void	keyboard_input()
{

}
