/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:44:06 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/16 14:46:21 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			pixel_color(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void		isometric(t_vec3 *point)
{
	float	tmp;

    tmp = point->x;
    point->x = (tmp - point->y) * cos(0.523599);
    point->y = (tmp + point->y) * sin(0.523599) - point->z;
}
