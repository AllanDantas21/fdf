#include "../includes/fdf.h"

void controls(float *x1, float *y1, float *x2, float *y2, fdf *data)
{
    control_zoom(x1, y1, x2, y2, data);
    isometric(x1, y1, data->z1);
    isometric(x2, y2, data->z2);
    control_pos(x1, y1, x2, y2, data);
}

void control_zoom(float *x1, float *y1, float *x2, float *y2, fdf *data)
{
    *x1 *= data->zoom; // coloquei o zoom na struct 
    *y1 *= data->zoom; // pra ficar mais facil 
    *x2 *= data->zoom; // de alterar
    *y2 *= data->zoom; //
}

 void control_pos(float *x1, float *y1, float *x2, float *y2, fdf *data)
{
    *x1 += data->pos;
    *y1 += data->pos;
    *x2 += data->pos;
    *y2 += data->pos;
}
