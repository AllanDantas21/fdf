#include "../includes/fdf.h"

void isometric(float *x, float *y, int z)
{
    *x = (*x - *y) * cos(0.8);
    *y = (*x + *y) * sin(0.8) - z;
}

static int my_max(int n1, int n2)
{
    if (n1 > n2)
        return (n1);
    return (n2); 
}

static int my_mod(int n)
{
    if (n < 0)
        return (-n);
    return (n);
}

void bresenham(float x1, float y1, float x2, float y2, fdf *data)
{
    data->z1 = data->matrix[(int)y1][(int)x1];
    data->z2 = data->matrix[(int)y2][(int)x2];
    controls(&x1, &y1, &x2, &y2, data);
    data->x_diff = x2 - x1;
    data->y_diff = y2 - y1;
 
    data->max = my_max(my_mod(data->x_diff), my_mod(data->y_diff));
    data->x_diff /= data->max;
    data->y_diff /= data->max;
    while((int)(x1 - x2) || (int)(y1 - y2))
    {
        put_pixel(x1, y1, data);
        x1 += data->x_diff;
        y1 += data->y_diff;
    }
}
