
#include "../includes/fdf.h"

char *count_height(int fd, int *height)
{
    *height = *height + 1;
    return(get_next_line(fd));
}

int get_height(char *file_name)
{
    int     fd;
    int     height;
    char    *tmp;
    char    *line;
   
    fd = open(file_name, O_RDONLY);
    line = get_next_line(fd);
    if (!line)
        return (-1);
    height = 1;
    while(line)
    {
        tmp = line;
        line = count_height(fd, &height);
        free(tmp);
    }
    height--;
    close(fd);
    return (height);
}
