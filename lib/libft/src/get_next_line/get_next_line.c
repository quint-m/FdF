/* ************************************************************************** */
/*																			  */
/*													:::  o_   ::::::	:::   */
/*	 get_next_line.c							   :+:	/	 :+::+:    :+:	  */
/*												  +:+	>	+:++:+	  +:+	  */
/*	 By: whaffman <whaffman@student.codam.nl>	 +#+  +:+  +#++#++:++#++	  */
/*												+#+ +#+#+ +#++#+	+#+ \o/   */
/*	 Created: 2024/07/15 16:59:55 by whaffman	#+#+# #+#+# #+#    #+#	 |	  */
/*	 Updated: 2024/07/15 17:00:24 by whaffman	###   ###  ###	  ###	/ \   */
/*																			  */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

static void	gnl_clean(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

static int	gnl_check_and_extract(char **line, char **stock)
{
	char	*temp1;
	char	*temp2;

	if (!stock || !*stock)
		return (0);
	temp1 = *stock;
	while (temp1 && *temp1 != '\n')
		if (!*temp1++)
			return (0);
	if (temp1)
		temp1++;
	temp2 = ft_strdup(temp1);
	*temp1 = '\0';
	*line = ft_strdup(*stock);
	free(*stock);
	*stock = temp2;
	if (!*line || !*stock)
	{
		gnl_clean((void **)line);
		gnl_clean((void **)stock);
		return (-1);
	}
	return (1);
}

static int	gnl_read(int fd, char **buffer, size_t size)
{
	int		bytes_read;

	if (!*buffer)
	{
		*buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!*buffer)
			return (-1);
	}
	bytes_read = read(fd, *buffer, size);
	if (bytes_read >= 0)
		(*buffer)[bytes_read] = '\0';
	return (bytes_read);
}

static int	gnl_read_file(int fd, char **stock, char **line)
{
	char	*buffer;
	char	*temp;
	int		bytes_read;

	buffer = NULL;
	bytes_read = gnl_read(fd, &buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		if (!*stock)
			*stock = ft_strdup(buffer);
		else
		{
			temp = *stock;
			*stock = ft_strjoin(temp, buffer);
			free(temp);
		}
		if (gnl_check_and_extract(line, stock))
			break ;
		bytes_read = gnl_read(fd, &buffer, BUFFER_SIZE);
	}
	free(buffer);
	if (!*stock)
		return (-1);
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*stock[1024];
	char		*line;
	int			status;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	if (stock[fd] && gnl_check_and_extract(&line, &stock[fd]))
		return (line);
	status = gnl_read_file(fd, &stock[fd], &line);
	if (status > 0)
		return (line);
	else if (status < 0)
	{
		gnl_clean((void **)&stock[fd]);
		return (NULL);
	}
	if (stock[fd] && *stock[fd])
	{
		line = ft_strdup(stock[fd]);
		gnl_clean((void **)&stock[fd]);
		if (line)
			return (line);
	}
	gnl_clean((void **)&stock[fd]);
	return (NULL);
}