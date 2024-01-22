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
    int width;
    int height;
    int **z_matrix;

    void    *mlx_ptr;
    void    *img_ptr;
    char    *img_data;
}   fdf;

#endif