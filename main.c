#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


int main(void)
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }

    line = get_next_line(fd);
    while (line)
    {
        printf("%s\n", line);
        free(line);
        line = get_next_line(fd);
    }

    close(fd);
    return (0);
}

/* gcc -o get_next_line main.c get_next_line.c -D BUFFER_SIZE=1024
./get_next_line   */ 