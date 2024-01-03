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

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "fdf");
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 2550);
	mlx_pixel_put(mlx_ptr, win_ptr, 251, 251, 2550);
	mlx_pixel_put(mlx_ptr, win_ptr, 252, 252, 2550);
	sleep(10);
	mlx_destroy_window(mlx_ptr, win_ptr);
	}
