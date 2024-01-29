#include "../includes/fdf.h"

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void	put_pixel(int x, int y, t_fdf *data)
{
	if (data->z1 || data->z2)
		mlx_pixel_put(data->mlx_ptr, data->img_ptr, x, y, 0Xff00000);
	else if (data->z1 == 0 || data->z2 == 0)
		mlx_pixel_put(data->mlx_ptr, data->img_ptr, x, y, 255);
	else
		mlx_pixel_put(data->mlx_ptr, data->img_ptr, x, y, 2147483647);
}

void	display_map(t_fdf *data)
{
	t_pos	p;

	p.y = 0;
	while (p.y < data->height)
	{
		p.x = 0;
		while (p.x < data->width)
		{
			if (!(p.x == data->width - 1))
				bresenham(p, p.x + 1, p.y, data);
			if (!(p.y == data->height - 1))
				bresenham(p, p.x, p.y + 1, data);
			p.x++;
		}
		p.y++;
	}
}
