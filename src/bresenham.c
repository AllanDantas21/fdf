#include "../includes/fdf.h"

static void    put_pixel(fdf *data, int x, int y, int x_index, int y_index)
{
    //static int color_test = 2147483647;
    (void)x_index;
    (void)y_index;
    if (data->z1 || data->z2)
        mlx_pixel_put(data->mlx_ptr, data->img_ptr, x, y, 255);
    else
        mlx_pixel_put(data->mlx_ptr, data->img_ptr, x, y, 2147483647);
    //color_test -= 1000;
}

static void adjust_zoom(float *x1, float *y1, float *x2, float *y2, fdf *data)
{
    *x1 *= data->zoom; // coloquei o zoom na struct 
    *y1 *= data->zoom; // pra ficar mais facil 
    *x2 *= data->zoom; // de alterar
    *y2 *= data->zoom; //
}

static void adjust_pos(float *x1, float *y1, float *x2, float *y2, fdf *data)
{
    *x1 += data->pos;
    *y1 += data->pos;
    *x2 += data->pos;
    *y2 += data->pos;
}

static void isometric(float *x, float *y, int z)
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

static void adjusts(float *x1, float *y1, float *x2, float *y2, fdf *data)
{
    adjust_zoom(x1, y1, x2, y2, data);
    isometric(x1, y1, data->z1);
    isometric(x2, y2, data->z2);
    adjust_pos(x1, y1, x2, y2, data);
}

void bresenham(float x1, float y1, float x2, float y2, fdf *data)
{
    data->x_index = x1;
    data->y_index = y1;
 
    data->z1 = data->matrix[(int)y1][(int)x1];
    data->z2 = data->matrix[(int)y2][(int)x2];
    adjusts(&x1, &y1, &x2, &y2, data);
    data->x_diff = x2 - x1;
    data->y_diff = y2 - y1;
 
    data->max = my_max(my_mod(data->x_diff), my_mod(data->y_diff));
    data->x_diff /= data->max;
    data->y_diff /= data->max;
    while((int)(x1 - x2) || (int)(y1 - y2))
    {
        put_pixel(data, x1, y1, data->x_index, data->y_index);
        x1 += data->x_diff;
        y1 += data->y_diff;
    }
}

    // x1 *= 25;
    // y1 *= 25;
    // x2 *= 25;
    // y2 *= 25;