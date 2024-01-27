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
	data->zoom = 20;
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
	ft_free((void **)data->matrix);
	free_map(data);
	free(data);
	sleep(5);
	

	//
	// Bresenham bresenham(20, 100, 90, 120, 255, data);
	// ****** test Matrix malloc; ******
	//
	// int i = 0;
	// int j;
	// while (i < data->height)
	// {
	// 	j = 0;
	// 	while(j < data->width)
	// 		{
	// 			printf("%3d", data->matrix[i][j]);
	// 			j++;
	// 		}
	// 		printf("\n");
	// 		i++;
	// }
	// 
	// **** test get infos map *****
	//printf("%d\n", data->height);
	//printf("%d", data->width);
	// data->mlx_ptr = mlx_init();
	// data->img_ptr = mlx_new_window(data->mlx_ptr, 800, 600, "fdf");
	// data->img_data =  mlx_new_image(data->mlx_ptr, 800, 600);
	
	// mlx_put_image_to_window(data->mlx_ptr, data->img_ptr, data->img_ptr, 0, 0);
	// sleep(10);
	// mlx_destroy_window(data->mlx_ptr, data->img_ptr);
	// read_file(data);
}
