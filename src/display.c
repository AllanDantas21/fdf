#include "../includes/fdf.h"

void	display_map(fdf *data)
{
	int x;
	int y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			bresenham(x, y, x + 1, y, 2147483647, data);
			bresenham(x, y, x, y + 1, 2147483647, data);
			x++;
		}
		y++;
	}
}