/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:03:40 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/16 16:02:50 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <cstdlib>
#include <string.h>

void	program_exit(const char *str)
{
	if (!str || !str[0])
	{
		perror(strerror(errno));
		exit(EXIT_FAILURE);
	}
	perror(str);
	exit(EXIT_FAILURE);
}

void	mlx_exit(void)
{
	ft_printf("Error occurred: %s\n", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}
