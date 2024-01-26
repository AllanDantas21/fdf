#include "../includes/fdf.h"

void bresenham(int x1, int y1, int x2, int y2, int color, fdf *data)
{
    x1 *= data->zoom; // coloquei o zoom na struct 
    y1 *= data->zoom; // pra ficar mais facil 
    x2 *= data->zoom; // de alterar
    y2 *= data->zoom; //

    int dx = x2 - x1;
    int dy = y2 - y1;

    int d = 2 * dy - dx; // valor inicial de d

    int incE = 2 * dy;    // incremento para mover E
    int incNE = 2 * (dy - dx); // incremento para mover NE

    int x = x1;
    int y = y1;
    mlx_pixel_put(data->mlx_ptr, data->img_ptr, x, y, color);

    // Lidar com linhas verticais
    if (dx == 0)
    {
        while (y < y2)
        {
            y++;
            mlx_pixel_put(data->mlx_ptr, data->img_ptr, x, y, color);
        }
        return;
    }

    // Lidar com linhas horizontais
    if (dy == 0)
    {
        while (x < x2)
        {
            x++;
            mlx_pixel_put(data->mlx_ptr, data->img_ptr, x, y, color);
        }
        return;
    }

    // Loop principal
    while (x != x2 || y != y2)
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


    // x1 *= 25;
    // y1 *= 25;
    // x2 *= 25;
    // y2 *= 25;