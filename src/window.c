/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:47:51 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/15 21:39:32 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

mlx_t	*create_window(int width, int height, const char *title)
{
	mlx_t	*window_handle;

	mlx_set_setting(MLX_MAXIMIZED, true);
	window_handle = mlx_init(width, height, title, false);
	if (!window_handle)
		p_exit();
	return (window_handle);
}
