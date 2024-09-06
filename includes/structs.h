/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:52:23 by aldantas          #+#    #+#             */
/*   Updated: 2024/09/06 17:54:29 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_pos
{
	float	x;
	float	y;
}			t_pos;

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**matrix;

	int		zoom;
	int		color;
	double	x_angle;
	double	y_angle;
	int		isometric_flag;
	int		rotate_left_flag;
	int		rotate_rigth_flag;
	int		mv_x;
	int		mv_y;

	int		z1;
	int		z2;

	void	*mlx_ptr;
	void	*img_ptr;
	float	y_diff;
	int		max;
}	t_fdf;


#endif