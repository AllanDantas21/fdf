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
#include <stdio.h>

void	init_image(fdf *data)
{
	data->mlx_ptr = mlx_init();
	data->img_ptr = mlx_new_window(data->mlx_ptr, 1200, 800, "fdf");
	data->img_data =  mlx_new_image(data->mlx_ptr, 1200, 800);
	data->mv_x = 150;
	data->mv_y = 150;
	data->zoom = 20;
}

int	moves(int key, fdf *data)
{
	if (key == ARROW_UP)
		data->mv_y -= 10;
	if (key == ARROW_RIGHT)
		data->mv_x += 10;
	if (key == ARROW_DOWN)
		data->mv_y += 10;
	if (key == ARROW_LEFT)
		data->mv_x -= 10;
	mlx_clear_window(data->mlx_ptr, data->img_ptr);
	display_map(data);
	return (0);
}

int	main(int argc, char **argv)
{
	char	*file_name;
	fdf		*data;

	if((argc != 2) || check_file_name(argv[1]))
		return(-1);
	file_name = argv[1];
	data = malloc(sizeof(fdf));
	init_image(data);
	get_map(file_name, data);
	display_map(data);
	mlx_key_hook(data->img_ptr, &moves, data);
	mlx_loop(data->mlx_ptr);
}
