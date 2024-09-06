/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:01:08 by aldantas          #+#    #+#             */
/*   Updated: 2024/09/06 17:50:08 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	bresenham(t_pos p, float x2, float y2, t_fdf *data)
{
	float	x_diff;
	float	y_diff;
	int		max;

	data->z1 = data->matrix[(int)p.y][(int)p.x];
	data->z2 = data->matrix[(int)y2][(int)x2];
	controls(&p, &x2, &y2, data);
	x_diff = x2 - p.x;
	y_diff = y2 - p.y;
	max = fmax(fabs(x_diff), fabs(y_diff));
	x_diff /= max;
	y_diff /= max;
	while ((int)(p.x - x2) || (int)(p.y - y2))
	{
		put_pixel(p.x, p.y, data);
		p.x += x_diff;
		p.y += y_diff;
	}
}
