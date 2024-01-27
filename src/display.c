#include "../includes/fdf.h"

void    put_pixel(int x, int y, fdf *data)
{
    if (data->z1 || data->z2)
        mlx_pixel_put(data->mlx_ptr, data->img_ptr, x, y, 255);
    else
        mlx_pixel_put(data->mlx_ptr, data->img_ptr, x, y, 2147483647);
}


void	display_map(fdf *data)
{
	float x;
	float y;

	y = 1;
	while (y < data->height)
	{
		x = 1;
		while (x < data->width)
		{
			if (!(x == data->width - 1)) // if para nao ligar reta quando chegar no x max
				bresenham(x, y, x + 1, y, data);
			if(!(y == data->height - 1)) // if para não ligar reta quando chegar no y max
				bresenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}