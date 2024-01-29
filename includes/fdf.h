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

# define HEIGHT 1920
# define WIDTH 1080
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
# define ARROW_DOWN 65364
# define ARROW_UP 65362

typedef struct s_pos
{
	float	x;
	float	y;
}			t_pos;

typedef struct s_fdf
{
	int	width;
	int	height;
	int	**matrix;

	int	zoom;
	int	mv_x;
	int	mv_y;

	float	x_diff;
	float	y_diff;
	int		max;
	int		z1;
	int		z2;

	void	*mlx_ptr;
	void	*img_ptr;
}   t_fdf;

void	control_zoom(t_pos *p, float *x2, float *y2, t_fdf *data);
void	control_pos(t_pos *p, float *x2, float *y2, t_fdf *data);
void	controls(t_pos *p, float *x2, float *y2, t_fdf *data);
void	bresenham(t_pos p, float x2, float y2, t_fdf *data);
void	isometric(float *x, float *y, int z);
void	get_map(char *file_name, t_fdf *data);
void	put_pixel(int x, int y, t_fdf *data);
void	display_map(t_fdf *data);
void	free_map(t_fdf *data);
void	ft_free(t_fdf *data);
int		get_infos(char *file_name, t_fdf *data);
int		count_width(char const *s, char c);
int		check_file_name(char *file_name);
int		destroy_fdf(t_fdf *data);
int		get_width(char *line);
char	*count_height(int fd, int *height);


#endif