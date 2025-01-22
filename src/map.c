/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:55:23 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/16 18:43:20 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

void	free_map(char ***map)
{
	int	w;
	int	h;

	h = 0;
	while (map[h])
	{
		w = 0;
		while (map[w])
			free(map[h][w++]);
		free(map[h++]);
	}
	free(map);
}

t_map	parse_map(const char *file)
{
	t_vec3		**points_parsed;
	char		*line;
	int			row;
	int			width;
	int			fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		program_exit("Failed opening map file");
	points_parsed = create_vertices(3);
	if (!points_parsed)
		program_exit("failed to create vertices array\n");
	row = 0;
	while ((line = get_next_line(fd)))
	{
		width = process_line(&points_parsed, ft_split(line, ' '), row);
		free(line);
		row++;
	}
	if ((row * width) - 1 != vertex_count(points_parsed))
		points_parsed = shrink(points_parsed, vertex_count(points_parsed) - (row * width));
	close(fd);
	return ((t_map) {.width = width, .height = row, .map = points_parsed});
}
