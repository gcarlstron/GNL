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
#include <stdio.h>
int     BUFFER_SIZE = 50;

void set_free(void *var)
{
    free(var);
    var = NULL;
}

char    *alocate_memory(char *var, int s)
{
    var = malloc(s * sizeof(char) + 1);
    var[0] = '\0';
    if (!var)
        return NULL;
    return var;
}

int read_file(int fd, char *buffer, char *backup)
{
    int rd;

    rd = read(fd, backup, BUFFER_SIZE);
    while (ft_strchr(backup, '\n') == NULL && rd > 0)
    {
        printf("%s",backup);
        rd = read(fd, buffer, BUFFER_SIZE);
        buffer[rd] = '\0';
        backup = ft_strjoin(backup, buffer);
    }
    return rd;
}

char *get_line(int fd, char *buffer, char *backup)
{
    int rd;
    if (ft_strchr(backup, '\n'))
    {
        printf("linha 60");
        backup = ft_strjoin(backup, buffer);
        return (backup);
    }
        
    rd = read_file(fd, buffer, backup);
    if (rd == 0 && !backup)
    {
        printf("linha 68");
        set_free(backup);
        return NULL;
    }
    if (ft_strchr(backup, '\n'))
    {
        printf("linha 74");
        backup = ft_strjoin(backup, buffer);
        return (backup);
    }
    printf("linha 78");
    return (buffer);
}

char *get_next_line(int fd)
{
    static char *backup;
    char        *buffer;
    char        *line;

    if (!fd){
        printf("erro FD");
        return NULL;
    }
        
    buffer = alocate_memory(buffer, BUFFER_SIZE);
    if (!backup)
        backup = alocate_memory(backup, BUFFER_SIZE);
    line = get_line(fd, buffer, backup);
    set_free(buffer);
    return (line);
}


/*

char *get_next_line(int fd)
{
    static char     *buff;
    char            *line;
    int      r;

    line = malloc(1);
    if(!buff)
    {
      buff = create_buff(buff);
      r = read(fd, buff, BUFFER_SIZE);
    }
    else
        line = ft_strjoin(line, buff);
    while (ft_strchr(buff, '\n') == NULL && r > 0)   
    {
        line = ft_strjoin(line, buff);
        r = read(fd, buff, BUFFER_SIZE);
        buff[r] = '\0';
    }
    line = ft_strjoin(line, buff);
    if (r > 0)
        buff = ft_strdup(ft_strchr(buff, '\n')+1);
    else
        return NULL;
    return (line);
}
*/