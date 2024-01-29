#include "../includes/fdf.h"

int	destroy_fdf(fdf *data)
{
	ft_free(data);
	mlx_destroy_window(data->mlx_ptr, data->img_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}

void	ft_free(fdf *data)
{
	int	i;

	i = 0;
	while (i < data->height)
	{
		free(data->matrix[i]);
		i++;
	}
	free(data->matrix);
}

char	*count_height(int fd, int *height)
{
	*height = *height + 1;
	return (get_next_line(fd));
}

int	get_width(char *line)
{
	int	width;

	width = count_width(line, ' ');
	return (width);
}

int	count_width(char const *s, char c)
{
	int	words;

	if (!s)
		return (0);
	words = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			words++;
		while (*s != c && *s)
			s++;
	}
	return (words);
}
