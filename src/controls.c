#include "../includes/fdf.h"

void	controls(t_pos *p, float *x2, float *y2, t_fdf *data)
{
	control_zoom(p, x2, y2, data);
	if (data->rotate_left_flag == 1)
	{
		rotate_left(&p->x, &p->y);	
		rotate_left(x2, y2);
	}
	if (data->rotate_rigth_flag == 1)
	{
		rotate_right(&p->x, &p->y);	
		rotate_right(x2, y2);
	}
	if (data->isometric_flag == 1)
	{
		isometric(&p->x, &p->y, data->z1, data);
		isometric(x2, y2, data->z2, data);
	}
	control_pos(p, x2, y2, data);
}

void	control_zoom(t_pos *p, float *x2, float *y2, t_fdf *data)
{
	p->x *= data->zoom;
	p->y *= data->zoom;
	*x2 *= data->zoom;
	*y2 *= data->zoom;
}

void	control_pos(t_pos *p, float *x2, float *y2, t_fdf *data)
{
	p->x += data->mv_x;
	p->y += data->mv_y;
	*x2 += data->mv_x;
	*y2 += data->mv_y;
}
