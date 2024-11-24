#include "get_next_line.h" // get_next_line()
#include <stdio.h>   // printf()
#include <fcntl.h>    // open()
#include <unistd.h>   // read(), write(), close()


int main(void)
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Error opening file");
        return (1);
    }

    line = get_next_line(fd);
    while (line)
    {
        printf("=>%s\n", line);
        free(line);
        line = get_next_line(fd);
    }

    close(fd);
    return (0);
}

/* gcc -o get_next_line main.c get_next_line.c -D BUFFER_SIZE=1024
gcc -D BUFFER_SIZE=50 get_next_line.c -o gnl main.c

cc main.c get_next_line.c get_next_line_utils.c -o test  

./get_next_line   */ 