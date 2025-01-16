/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:47:51 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/16 16:04:46 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

mlx_t	*create_window(int width, int height, const char *title)
{
	mlx_t	*window_handle;

	mlx_set_setting(MLX_MAXIMIZED, false);
	window_handle = mlx_init(width, height, title, false);
	if (!window_handle)
		mlx_exit();
	return (window_handle);
}
