#include "../includes/fdf.h"

static void    put_pixel(fdf *data, int x, int y, int color, int x_index, int y_index)
{
    (void)color;
    //static int color_test = 2147483647;
    if (data->matrix[y_index][x_index])
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

void bresenham(float x, float y, float x1, float y1, int color, fdf *data)
{
    int x_index = x;
    int y_index = y;
    float   x_diff;
    float   y_diff;
    int     max;
    int     z;
    int     z1;

    z = data->matrix[(int)y][(int)x];
    z1 = data->matrix[(int)y1][(int)x1];
    adjust_zoom(&x, &y, &x1, &y1, data);
    isometric(&x, &y, z);
    isometric(&x1, &y1, z1);
    adjust_pos(&x, &y, &x1, &y1, data);
    x_diff = x1 - x;
    y_diff = y1 - y;
 
    max = my_max(my_mod(x_diff), my_mod(y_diff));
    x_diff /= max;
    y_diff /= max;
    while((int)(x - x1) || (int)(y - y1))
    {
        put_pixel(data, x, y, color, x_index, y_index);
        x += x_diff;
        y += y_diff;
    }
}

    // x1 *= 25;
    // y1 *= 25;
    // x2 *= 25;
    // y2 *= 25;