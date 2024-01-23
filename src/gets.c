
#include "../includes/fdf.h"

static char *count_height(int fd, int *height)
{
	*height = *height + 1;
	return(get_next_line(fd));
}

static int get_width(char *line)
{
	int	width;

	width = count_width(line, ' ');
	return (width);
}

int get_infos(char *file_name, fdf *data)
{
	int		fd;
	int		height;
	char	*tmp;
	char	*line;
   
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (-1);
	data->width = get_width(line);
	height = 1;
	while(line)
	{
		tmp = line;
		line = count_height(fd, &height);
		free(tmp);
	}
	height--;
	close(fd);
	data->height = height;
	return (0);
}