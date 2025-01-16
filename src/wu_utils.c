/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_part.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:15:01 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/15 21:17:57 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	ipart(float x)
{
	return (floor(x));
}

float	fpart(float x)
{
	return (x - ipart(x));
}

float	rfpart(float x)
{
	return (1 - fpart(x));
}
