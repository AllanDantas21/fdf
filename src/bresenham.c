#include "../includes/fdf.h"
#include <math.h>

static void    put_pixel(fdf *data, int x, int y, int color)
{
    mlx_pixel_put(data->mlx_ptr, data->img_ptr, x, y, color);
}

static void adjust_zoom(int *x1, int *y1, int *x2, int *y2, fdf *data)
{
    *x1 *= data->zoom; // coloquei o zoom na struct 
    *y1 *= data->zoom; // pra ficar mais facil 
    *x2 *= data->zoom; // de alterar
    *y2 *= data->zoom; //
}

void bresenham(int x1, int y1, int x2, int y2, int color, fdf *data)
{
    adjust_zoom(&x1, &y1, &x2, &y2, data);

    int dx = x2 - x1;
    int dy = y2 - y1;
    int d = 2 * dy - dx;
    int incE = 2 * dy;
    int incNE = 2 * (dy - dx);
    int x = x1;
    int y = y1;

    put_pixel(data, x, y, color);

    if (dx == 0) {
        while (y < y2) {
            y++;
            put_pixel(data, x, y, color);
        }
    } else if (dy == 0) {
        while (x < x2) {
            x++;
            put_pixel(data, x, y, color);
        }
    } else {
        while (x != x2 || y != y2) {
            if (d <= 0) {
                d += incE;
                x++;
            } else {
                d += incNE;
                x++;
                y++;
            }
            put_pixel(data, x, y, color);
        }
    }
}


    // x1 *= 25;
    // y1 *= 25;
    // x2 *= 25;
    // y2 *= 25;