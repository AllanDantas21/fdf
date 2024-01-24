#include "../includes/fdf.h"

static char	*count_height(int fd, int *height)
{
	*height = *height + 1;
	return(get_next_line(fd));
}

static int	get_width(char *line)
{
	int	width;

	width = count_width(line, ' ');
	return (width);
}

int	get_infos(char *file_name, fdf *data)
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

void	malloc_map(int *i, fdf *data)
{
	data->matrix = malloc(sizeof(int *) * (data->height + 1));
	while (*i <=data->height)
		data->matrix[*i++] = malloc(sizeof(int) * (data->width + 1));
	i = 0;
}

void	fill_map(int *line_matrix, char	*line)
{
	char	**values;
	int		i;

	i = 0;
	values = ft_split(line, ' ');
	while(values[i])
	{
		line_matrix[i] = ft_atoi(values[i]);
		free(values[i++]);
	}
	free(values);
}

void	get_map(char *file_name, fdf *data)
{
	char	*line;
	char	*tmp;
	int		fd;
	int		i;

	i = 0;
	get_infos(file_name, data);
	malloc_map(&i, data);
	fd = open(file_name, O_RDONLY);
	line = (get_next_line(fd));
	while(line)
	{
		tmp = line;
		fill_map(data->matrix[i++], tmp);
		line = get_next_line(fd);
		free(tmp);
	}
	close(fd);
	data->matrix[i] = NULL;
}