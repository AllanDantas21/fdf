/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 03:23:19 by aldantas          #+#    #+#             */
/*   Updated: 2024/01/03 03:29:33 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"

# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
# define ARROW_DOWN 65364
# define ARROW_UP 65362

typedef struct
{
	float	x;
	float	y;
}	pos;


typedef struct
{
	int	width;
	int	height;
	int	**matrix;

	int	zoom;
	int mv_x;
	int mv_y;

	float   x_diff;
	float   y_diff;
	int     max;
	int     z1;
	int     z2;

	void	*mlx_ptr;
	void	*img_ptr;
}   fdf;

void 	control_zoom(pos *p, float *x2, float *y2, fdf *data);
void 	control_pos(pos *p, float *x2, float *y2, fdf *data);
void 	controls(pos *p, float *x2, float *y2, fdf *data);
void 	bresenham(pos p, float x2, float y2, fdf *data);
void	isometric(float *x, float *y, int z);
void	get_map(char *file_name, fdf *data);
void    put_pixel(int x, int y, fdf *data);
void	display_map(fdf *data);
void	free_map(fdf *data);
void	ft_free(fdf *data);
int		get_infos(char *file_name, fdf *data);
int		count_width(char const *s, char c);
int		check_file_name(char *file_name);
int		destroy_fdf(fdf *data);

#endif