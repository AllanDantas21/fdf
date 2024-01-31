/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:01:48 by aldantas          #+#    #+#             */
/*   Updated: 2024/01/31 14:01:50 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fdf.h"

void	arrows(int key, t_fdf *data)
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

void	zoom(int key, t_fdf *data)
{
	if (key == XK_minus)
		data->zoom -= 1;
	if (key == XK_equal)
		data->zoom += 1;
}

void	translation(int key, t_fdf *data)
{
	if (key == KEY_W)
		data->x_angle += 0.05;
	if (key == KEY_S)
		data->y_angle -= 0.05;
	if (key == KEY_Q)
	{
		data->x_angle += 0.05;
		data->y_angle += 0.05;
	}
	if (key == KEY_E)
	{
		data->x_angle -= 0.05;
		data->y_angle -= 0.05;
	}
}

void	views(int key, t_fdf *data)
{
	if (key == KEY_I)
		defaults(data);
	if (key == KEY_C)
		change_color(data);
	if (key == KEY_P)
	{
		data->x_angle = 0.5235;
		data->y_angle = 2.6179;
	}
	if (key == KEY_F)
	{
		if (data->isometric_flag == 1)
			data->isometric_flag = 0;
		else if (data->isometric_flag == 0)
			data->isometric_flag = 1;
	}
}

void	rotation(int key, t_fdf *data)
{
	if (key == KEY_Z)
		change_r_left(data);
	if (key == KEY_X)
		change_r_right(data);
}
