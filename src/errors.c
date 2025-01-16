/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:03:40 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/16 16:57:13 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	program_exit(const char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	mlx_exit(void)
{
	ft_printf("Error occurred: %s\n", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}
