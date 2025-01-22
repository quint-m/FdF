#include "fdf.h"

static t_vec3	*create_vertex(float x, float y, float z)
{
	t_vec3	*v;

	v = malloc(sizeof(t_vec3));
	if (!v)
		return (NULL);
	v->x = x;
	v->y = y;
	v->z = z;
	return (v);
}

t_vec3	**create_vertices(int initial_size)
{
	t_vec3	**vertices;
	int		i;

	vertices = malloc((initial_size + 1) * sizeof(t_vec3 *));
	if (!vertices)
		return (NULL);
	i = 0;
	while (i < initial_size)
		vertices[i++] = create_vertex(0.0, 0.0, 0.0);
	vertices[initial_size] = NULL;
	return (vertices);
}

size_t	vertex_count(t_vec3 **vertices)
{
	size_t	i;

	i = 0;
	while (vertices[i])
		i++;
	return (i);
}

t_vec3	**shrink(t_vec3 **src, int n)
{
	t_vec3	**dest;
	size_t	v_count;
	size_t	i;
	if (!src)
		return (create_vertices(n));
	v_count = vertex_count(src);
	dest = malloc((v_count - n + 1) * sizeof(t_vec3 *));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i] && i < v_count - n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = NULL;
	while (i < v_count)
	{
		free(src[i]);
		i++;
	}
	free(src);
	return (dest);
}

t_vec3	**resize(t_vec3 **src, int n)
{
	t_vec3	**dest;
	size_t	i;
	size_t	v_count;
	
	if (!src)
		return (create_vertices(n));
	v_count = vertex_count(src);
	dest = malloc((v_count + n + 1) * sizeof(t_vec3 *));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < v_count)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < v_count + n && n > 0)
		dest[i++] = create_vertex(0.0, 0.0, 0.0);
	free(src);
	dest[i] = NULL;
	return (dest);
}

int	get_width(char **line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

int process_line(t_vec3 ***vertices, char **line, int row)
{
	int width;
	int i;

	if (!line)
		program_exit("Trying to parse an empty line");
	width = get_width(line);
	i = 0;
	while (line[i])
	{
		if (row * width + i >= (int) vertex_count(*vertices))
			*vertices = resize(*vertices, vertex_count(*vertices));
		(*vertices)[row * width + i]->x = i;
		(*vertices)[row * width + i]->y = row;
		(*vertices)[row * width + i]->z = ft_atoi(line[i]);
		i++;
	}
	i = 0;
	while (line[i])
        free(line[i++]);
	free(line);
	return width;
}
