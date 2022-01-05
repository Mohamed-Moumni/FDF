/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 14:49:22 by mmoumni           #+#    #+#             */
/*   Updated: 2022/01/04 12:35:22 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keys.h"

int	close_win(t_fdf *param)
{
	mlx_destroy_image(param->mlx_ptr, param->img_ptr);
	mlx_destroy_window(param->mlx_ptr, param->win_ptr);
	free(param->mlx_ptr);
	exit(0);
}

int	esc_close(int key, t_fdf *param)
{
	if (key == ESC)
	{
		mlx_destroy_image(param->mlx_ptr, param->img_ptr);
		mlx_destroy_window(param->mlx_ptr, param->win_ptr);
		free(param->mlx_ptr);
		exit(0);
	}
	return (0);
}
