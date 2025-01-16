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

static void	create_map(char ***map, int h)
{
	int	w;
	int	**res;

	w = 0;
	h = 0;
	res = ft_calloc(h, sizeof(int *));
	while (map[h])
	{
		while (map[h][w])
		{
			res[h][w] = ft_atoi(map[h][w]);
			w++;
		}
		h++;
	}
	free_map(map);
}

static void	parse_lines(int fd)
{
	int		h;
	char	*line;
	char	***map;

	map = ft_calloc(100, sizeof(char **));
	while ((line = get_next_line(fd)))
	{
		map[h++] = ft_split(line, ' ');
		free(line);
	}
	create_map(map, h);
}

void	parse_map(const char *file)
{
	int		height;
	int		width;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		program_exit("FD is invalid");
	parse_lines(fd);
	close(fd);
}
