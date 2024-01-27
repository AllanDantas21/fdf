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
# include "../libft/libft.h"
# include "../minilibx/mlx.h"

typedef struct {
	int x;
	int y;
	int z;
}	point;

typedef struct
{
	/* map infos*/
	int	width;
	int	height;
	int	**matrix;

	/**/
	int	zoom;
	int	pos;

	/* Bresenham utils*/
	int x_index;
	int y_index;
	float   x_diff;
	float   y_diff;
	int     max;
	int     z1;
	int     z2;

	void	*mlx_ptr;
	void	*img_ptr;
	char	*img_data;
}   fdf;

void	display_map(fdf *data);
void 	bresenham(float x1, float y1, float x2, float y2, fdf *data);
void	get_map(char *file_name, fdf *data);
int		count_width(char const *s, char c);
int		check_file_name(char *file_name);
int		get_infos(char *file_name, fdf *data);
void	free_map(fdf *data);
void	ft_free(void **mat);

#endif