/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:53:34 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/23 12:54:10 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_program_error(const char *err, int system_error)
{
	if (system_error)
	{
		perror(err);
		exit(EXIT_FAILURE);
	}
	ft_putstr_fd((char *)err, 2);
	exit(EXIT_FAILURE);
}

int	ft_get_default_color(int x, int y, t_env *env)
{
	float p;

	p = (float) env->map->grid[x + y * env->map->width].z / abs(env->map->z_max - env->map->z_min);
	if (p < 0.2)
		return (0x432371FF);
	else if (p < 0.4)
		return (0x714674FF);
	else if (p < 0.6)
		return (0x9F6976FF);
	else if (p < 0.8)
		return (0xCC8B79FF);
	else
		return (0xFAAE7BFF);
}

