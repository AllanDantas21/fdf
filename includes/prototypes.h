/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:52:21 by aldantas          #+#    #+#             */
/*   Updated: 2024/09/06 17:54:29 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

void	control_zoom(t_pos *p, float *x2, float *y2, t_fdf *data);
void	control_pos(t_pos *p, float *x2, float *y2, t_fdf *data);
void	controls(t_pos *p, float *x2, float *y2, t_fdf *data);
void	bresenham(t_pos p, float x2, float y2, t_fdf *data);
void	isometric(float *x, float *y, int z, t_fdf *data);
void	get_map(char *file_name, t_fdf *data);
void	put_pixel(int x, int y, t_fdf *data);
void	display_map(t_fdf *data);
void	ft_free(t_fdf *data);
void	defaults(t_fdf *data);
int		get_infos(char *file_name, t_fdf *data);
int		count_width(char const *s, char c);
int		check_file_name(char *file_name);
int		destroy_fdf(t_fdf *data);
int		get_width(char *line);
char	*count_height(int fd, int *height);

void	rotate_left(float *x, float *y);
void	rotate_right(float *x, float *y);
void	change_r_right(t_fdf *data);
void	change_r_left(t_fdf *data);

void	change_color(t_fdf *data);
// int		moves(int key, t_fdf *data);
void	arrows(int key, t_fdf *data);
void	zoom(int key, t_fdf *data);
void	translation(int key, t_fdf *data);
void	rotation(int key, t_fdf *data);
void	views(int key, t_fdf *data);

#endif