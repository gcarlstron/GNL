/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-h <italogholanda@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 07:22:13 by igomes-h          #+#    #+#             */
/*   Updated: 2021/09/28 13:22:42 by igomes-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	get_line(char **saved_buf, char **line)
{
	char	*tmp;
	int		i;

	i = 0;
	while ((*saved_buf)[i] != '\n' && (*saved_buf)[i])
		i++;
	if ((*saved_buf)[i] == '\n')
	{
		tmp = *saved_buf;
		*line = ft_substr(tmp, 0, i + 1);
		*saved_buf = ft_strdup(tmp + i + 1);
		free(tmp);
	}
	else
	{
		*line = ft_strdup(*saved_buf);
		free(*saved_buf);
		*saved_buf = 0;
	}
}

static void	read_fd(char **buf, char **saved_buf, char **line, int fd)
{
	char	*tmp;
	int		bytes;

	bytes = 1;
	if (!*saved_buf)
		*saved_buf = ft_strdup("");
	while (bytes && !ft_strchr(*saved_buf, '\n'))
	{
		bytes = read(fd, *buf, BUFFER_SIZE);
		(*buf)[bytes] = 0;
		tmp = *saved_buf;
		*saved_buf = ft_strjoin(tmp, *buf);
		free(tmp);
	}
	get_line(saved_buf, line);
	if (!**line)
	{
		free(*line);
		*line = 0;
	}
}

char	*get_next_line(int fd)
{
	static char	*saved_buf;
	char		*buf;
	char		*line;

	if (BUFFER_SIZE <= 0)
		return (0);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	if (read(fd, buf, 0) < 0)
	{
		free(buf);
		return (0);
	}
	read_fd(&buf, &saved_buf, &line, fd);
	free(buf);
	if (!line)
		return (0);
	return (line);
}
