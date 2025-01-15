/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:03:40 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/15 19:04:01 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	p_exit(void)
{
	ft_printf("Error occurred: %s\n", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}
