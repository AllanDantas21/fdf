#include "../includes/fdf.h"

void	controls(pos *p, float *x2, float *y2, fdf *data)
{
	control_zoom(p, x2, y2, data);
	isometric(&p->x, &p->y, data->z1);
	isometric(x2, y2, data->z2);
	control_pos(p, x2, y2, data);
}

void	control_zoom(pos *p, float *x2, float *y2, fdf *data)
{
	p->x *= data->zoom;
	p->y *= data->zoom;
	*x2 *= data->zoom;
	*y2 *= data->zoom;
}

void	control_pos(pos *p, float *x2, float *y2, fdf *data)
{
	p->x += data->mv_x;
	p->y += data->mv_y;
	*x2 += data->mv_x;
	*y2 += data->mv_y;
}
