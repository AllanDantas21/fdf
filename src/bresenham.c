#include "../includes/fdf.h"

void    bresenham(int x1, int y1, int x2, int y2, int color, fdf *data)
{
    int dx = x2 - x1;
    int dy = y2 - x1;

    int d = 2 * (dy - dx); // valor inicial de d

    int incE = 2 * dy; // incremento para mover E

    int incNE = 2 * (dy - dx); // incremento para mover NE

    int x = x1;
    int y = y1;
    mlx_pixel_put(data->mlx_ptr, data->img_ptr, x, y, color);
    while (x < x2)
    {
        if (d <= 0)
        {
            d += incE;
            x++;
        }
        else
        {
            d += incNE;
            x++;
            y++;
        }
        mlx_pixel_put(data->mlx_ptr, data->img_ptr, x, y, color);
    }
}