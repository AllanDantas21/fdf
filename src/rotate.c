#include "../includes/fdf.h"

void	rotate_left(float *x, float *y)
{
	*x = *x;
	*y = -*y;
}
void	rotate_right(float *x, float *y)
{
	*x = -*x;
	*y = *y;
}

void	change_r_right(t_fdf *data)
{
	if (data->rotate_rigth_flag == 0)
		data->rotate_rigth_flag = 1;
	else if (data->rotate_rigth_flag == 1)
		data->rotate_rigth_flag = 0;
}

void	change_r_left(t_fdf *data)
{
	if (data->rotate_left_flag == 0)
		data->rotate_left_flag = 1;
	else if (data->rotate_left_flag == 1)
		data->rotate_left_flag = 0;
}
