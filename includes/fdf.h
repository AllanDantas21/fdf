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

typedef struct
{
	int	width;
	int	height;
	int	**matrix;

	int	zoom;

	void	*mlx_ptr;
	void	*img_ptr;
	char	*img_data;
}   fdf;

void    display_map(fdf *data);
void 	bresenham(int x1, int y1, int x2, int y2, int color, fdf *data);
void	get_map(char *file_name, fdf *data);
int		count_width(char const *s, char c);
int		check_file_name(char *file_name);
int		get_infos(char *file_name, fdf *data);
void	ft_free(void **mat);

#endif