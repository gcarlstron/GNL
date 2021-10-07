#include "get_next_line.h"
#include <sys/stat.h> 
#include <fcntl.h>
#include <stdio.h>

int main(){
    int fd;
    int n;
    char *line;

    n = 1;
    fd = open("texto.txt", O_RDONLY);
    if(!fd)
        return -1;
    while (line = get_next_line(fd))
        printf("foi >%d %s\n",n++, line);
}