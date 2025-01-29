/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:52:27 by qmennen           #+#    #+#             */
/*   Updated: 2025/01/23 13:29:43 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

int	ft_get_map_width(const char *file)
{
	int		fd;
	int		width;
	char	*line;
	int		i;

	i = -1;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_program_error("open error", 1);
	width = 0;
	line = get_next_line(fd);
	if (*line == '\0')
		ft_program_error("invalid map (empty)", 0);
	while (line[++i])
		if (line[i] != ' ' && (line[i + 1] == ' ' || line[i + 1] == '\0'))
			width++;
	free(line);
	while ((line = get_next_line(fd)))
		free(line);
	free(line);
	if (close(fd) == -1)
		ft_program_error("close error", 1);
	return (width);
}

int	ft_get_map_height(const char *file)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_program_error("failed to open map file", 1);
	height = 0;
	while ((line = get_next_line(fd)))
	{
		height++;
		free(line);
	}
	free(line);
	if (close(fd) == -1)
		ft_program_error("failed to close the map file", 1);
	return (height);
}

static void	ft_row(int y, int width, char *line, t_map *map)
{
	int		x;
	char	*split;
	char	*hex;

	x = 0;
	split = line;
	while (*split)
	{
		while (*split == ' ')
			split++;
		if (*split != ' ' && *split != '\0')
		{
			//TODO: What is normal characters are found? (no hex)
			hex = ft_strchr(split, ',');
			map->grid[x + y * map->width] = (t_point){x, y, ft_atoi(split), 0};
			if (hex)
				map->grid[x + y * map->width].color = (ft_atoi_base(hex + 1, "0123456789ABCDEF") << 8 | 0xFF);
			x++;
		}
		while (*split && *split != ' ')
			split++;
	}
	if (x != width)
		ft_program_error("map width is inconsistent\n", 0);
}

static void	ft_z_bounds(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width * map->height)
	{
		if (map->grid[i].z < map->z_min)
			map->z_min = map->grid[i].z;
		else if(map->grid[i].z > map->z_max)
			map->z_max = map->grid[i].z;
		i++;
	}
}

int	ft_validate_map(const char *file, t_map *map)
{
	int		fd;
	char	*line;
	int		y;

	if (! ft_strnstr(file, ".fdf", ft_strlen(file)))
		ft_program_error("map file must be in fdf format", 0);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_program_error("opening map file failed", 1);
	y = 0;
	map->width = ft_get_map_width(file);
	map->height = ft_get_map_height(file);
	map->grid = malloc(sizeof(t_point) * map->width * map->height);
	while ((line = get_next_line(fd)))
	{
		ft_row(y, map->width, line, map);
		free(line);
		y++;
	}
	free(line);
	ft_z_bounds(map);
	close(fd);
	return (1);
}
