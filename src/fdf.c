/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 03:23:19 by aldantas          #+#    #+#             */
/*   Updated: 2024/01/03 03:29:33 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fdf.h"

void	init_image(t_fdf *data)
{
	data->mlx_ptr = mlx_init();
	data->img_ptr = mlx_new_window(data->mlx_ptr, \
	HEIGHT, WIDTH, "fdf - aldantas");
}

void	defaults(t_fdf *data)
{
	data->mv_x = WIDTH / 6;
	data->mv_y = HEIGHT / 6;
	data->zoom = 20;
	data->color = BLUE;
	data->rotate_left_flag = 0;
	data->rotate_rigth_flag = 0;
	data->x_angle = 0.8;
	data->y_angle = 0.8;
	data->isometric_flag = 1;
}

int	moves(int key, t_fdf *data)
{
	arrows(key, data);
	zoom(key, data);
	views(key, data);
	translation(key, data);
	rotation(key, data);
	mlx_clear_window(data->mlx_ptr, data->img_ptr);
	display_map(data);
	if (key == XK_Escape)
		destroy_fdf(data);
	return (0);
}

int	main(int argc, char **argv)
{
	char		*file_name;
	t_fdf		data;

	if ((argc != 2) || check_file_name(argv[1]))
		return (-1);
	file_name = argv[1];
	init_image(&data);
	defaults(&data);
	get_map(file_name, &data);
	display_map(&data);
	mlx_key_hook(data.img_ptr, &moves, &data);
	mlx_hook(data.img_ptr, 17, 0, &destroy_fdf, &data);
	mlx_loop(data.mlx_ptr);
}
