/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpacheco <gpacheco@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 21:18:45 by gpacheco          #+#    #+#             */
/*   Updated: 2021/10/06 22:14:25 by gpacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
int     BUFFER_SIZE = 42;

void set_free(void *var)
{
    free(var);
    var = NULL;
}




char *get_next_line(int fd)
{
    static char     *buff;
    char            *line;
    int             r;

    r = 0;
    line = malloc(1);
    buff = malloc(BUFFER_SIZE * sizeof(char) + 1);
    buff[r] = '\0';
    if (!buff)
        buff[r] = '\0';
    while (ft_strchr(buff, '\n') == NULL)   
    {
        line = ft_strjoin(line, buff);
        r = read(fd, buff, BUFFER_SIZE);
        buff[r] = '\0';
    }

    line = ft_strjoin(line, buff);
    return (line);
}