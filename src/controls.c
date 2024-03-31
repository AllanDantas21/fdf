/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:01:26 by aldantas          #+#    #+#             */
/*   Updated: 2024/03/31 14:52:09 by aldantas         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/fdf.h"
void	defaults(t_fdf *data)
{
	data->width = 0;
	data->height = 0;
	data->matrix = NULL;
	data->zoom = 15;
	data->color = BLUE;
	data->x_angle = 0.8;
	data->y_angle = 0.8;
	data->mv_x = (WIDTH - data->width) / 2;
	data->mv_y = HEIGHT / 5;
	data->z1 = 0;
	data->z2 = 0;
}

void	controls(t_pos *p, float *x2, float *y2, t_fdf *data)
{
	control_zoom(p, x2, y2, data);
	isometric(&p->x, &p->y, data->z1, data);
	isometric(x2, y2, data->z2, data);
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
