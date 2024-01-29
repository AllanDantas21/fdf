#include "../includes/fdf.h"

static int	my_max(int n1, int n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

static int	my_mod(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	bresenham(pos p, float x2, float y2, fdf *data)
{
	data->z1 = data->matrix[(int)p.y][(int)p.x];
	data->z2 = data->matrix[(int)y2][(int)x2];
	controls(&p, &x2, &y2, data);
	data->x_diff = x2 - p.x;
	data->y_diff = y2 - p.y;
	data->max = my_max(my_mod(data->x_diff), my_mod(data->y_diff));
	data->x_diff /= data->max;
	data->y_diff /= data->max;
	while ((int)(p.x - x2) || (int)(p.y - y2))
	{
		put_pixel(p.x, p.y, data);
		p.x += data->x_diff;
		p.y += data->y_diff;
	}
}
