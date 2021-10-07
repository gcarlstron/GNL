#include "get_next_line.h"
#include <sys/stat.h> 
#include <fcntl.h>
#include <stdio.h>

int main(){
    int fd;

    fd = open("texto.txt", O_RDONLY);
    if(!fd)
        return -1;
    printf("foi > %s\n",get_next_line(fd));
}