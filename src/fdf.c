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

int	main(int argc, char **argv)
{
	if(argc != 2)
		return (-1);
	if(check_file_name(argv[1]))
		return(-1);
	printf("extensão aceita");
	// fdf		*data;

	// data = (fdf*)malloc(sizeof(fdf));
	
	// data->mlx_ptr = mlx_init();
	// data->img_ptr = mlx_new_window(data->mlx_ptr, 800, 600, "fdf");
	// data->img_data =  mlx_new_image(data->mlx_ptr, 800, 600);
	
	// mlx_put_image_to_window(data->mlx_ptr, data->img_ptr, data->img_ptr, 0, 0);
	// sleep(10);
	// mlx_destroy_window(data->mlx_ptr, data->img_ptr);
	// read_file(data);
}
