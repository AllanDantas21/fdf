/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 03:23:19 by aldantas          #+#    #+#             */
/*   Updated: 2024/01/31 17:41:45 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fdf.h"

void	init_image(t_fdf *data)
{
	data->mlx_ptr = mlx_init();
	data->img_ptr = mlx_new_window(data->mlx_ptr, \
	HEIGHT, WIDTH, "fdf - aldantas");
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
	mlx_key_hook(data.img_ptr, moves, &data);
	mlx_hook(data.img_ptr, 17, 0, destroy_fdf, &data);
	mlx_loop(data.mlx_ptr);
}
