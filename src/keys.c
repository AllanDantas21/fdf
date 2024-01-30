#include "../includes/fdf.h"

void arrows(int key, t_fdf *data)
{
	if (key == ARROW_UP)
		data->mv_y -= 10;
	if (key == ARROW_RIGHT)
		data->mv_x += 10;
	if (key == ARROW_DOWN)
		data->mv_y += 10;
	if (key == ARROW_LEFT)
		data->mv_x -= 10;
}

void zoom(int key, t_fdf *data)
{
	if (key == XK_minus)
		data->zoom -= 1;
	if (key == XK_equal)
		data->zoom += 1;
	if (key == XK_c)
		change_color(data);
}

void translation(int key, t_fdf *data)
{
	if (key == XK_w)
		data->x_angle += 0.05;
	if (key == XK_s)
		data->y_angle -= 0.05;
	if (key == XK_q)
	{
		data->x_angle += 0.05;
		data->y_angle += 0.05;
	}
	if (key == XK_e)
	{
		data->x_angle -= 0.05;
		data->y_angle -= 0.05;
	}
}

void	views(int key, t_fdf *data)
{
	if (key == XK_i)
		defaults(data);
	if (key == XK_p)
	{
		data->x_angle = 0.5235;
		data->y_angle = 2.6179;
	}
	if (key == XK_f)
	{
		if (data->isometric_flag == 1)
			data->isometric_flag = 0;
		else if (data->isometric_flag == 0)
			data->isometric_flag = 1;
	}
}

void rotation(int key, t_fdf *data)
{
	if (key == XK_z)
		change_r_left(data);
	if (key == XK_x)
		change_r_right(data);
}
