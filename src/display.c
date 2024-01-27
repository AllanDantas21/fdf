#include "../includes/fdf.h"

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
				bresenham(x, y, x + 1, y, 2147483647, data);
			if(!(y == data->height - 1)) // if para não ligar reta quando chegar no y max
				bresenham(x, y, x, y + 1, 2147483647, data);
			x++;
		}
		y++;
	}
}