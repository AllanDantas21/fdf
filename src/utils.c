#include "../includes/fdf.h"

int	destroy_fdf(fdf *data)
{
	ft_free((void **)data);
	mlx_destroy_window(data->mlx_ptr, data->img_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data);
	exit(0);
}

void	ft_free(void **mat)
{
	size_t	i;

	i = 0;
	while (mat[i])
		free(mat[i++]);
	free(mat);
}

int count_width(char const *s, char c)
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
