/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handel_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 15:13:07 by mmoumni           #+#    #+#             */
/*   Updated: 2022/01/02 21:04:53 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keys_bonus.h"

int	close_win(void *param)
{
	(void)param;
	exit(1);
}

int	key_zoom(int key, t_fdf *param)
{
	if (key == ZOOM_IN)
	{
		param->zoom += 2;
		param->x_pos -= 10;
		param->y_pos -= 10;
	}
	else if (key == ZOOM_OUT)
	{
		if (param->zoom < 2)
			param->zoom = 1;
		else
		{
			param->zoom -= 2;
			param->x_pos += 10;
			param->y_pos += 10;
		}
	}
	else if (key == ESC)
	{
		(void)param;
		mlx_destroy_image(param->mlx_ptr, param->img_ptr);
		mlx_destroy_window(param->mlx_ptr, param->win_ptr);
		exit(1);
	}
	return (0);
}

int	translate_rot_map(int key, t_fdf *param)
{
	if (key == UP)
		param->y_pos -= 20;
	else if (key == DOWN)
		param->y_pos += 20;
	else if (key == LEFT)
		param->x_pos -= 20;
	else if (key == RIGHT)
		param->x_pos += 20;
	else if (key == X)
	{
		param->rot = 1;
		param->alpha += 0.2;
	}
	else if (key == Y)
	{
		param->rot = 2;
		param->beta += 0.2;
	}
	else if (key == Z)
	{
		param->rot = 3;
		param->teta += 0.2;
	}
	return (0);
}

int	altitude_and_proj(int key, t_fdf *param)
{
	if (key == PLUS_ALT)
	{
		param->altitude += 2;
	}
	else if (key == MINUS_ALT)
	{
		param->altitude -= 2;
	}
	if (key == THREE_D)
	{
		param->project = 1;
	}
	else if (key == TWO_D)
	{
		param->project = 0;
	}
	return (0);
}

int	event_key(int key, t_fdf *param)
{
	key_zoom(key, param);
	translate_rot_map(key, param);
	altitude_and_proj(key, param);
	mlx_clear_window((param)->mlx_ptr, (param)->win_ptr);
	mlx_destroy_image(param->mlx_ptr, param->img_ptr);
	param->img_ptr = mlx_new_image(param->mlx_ptr, WIDTH, HEIGHT);
	ft_draw((param));
	mlx_put_image_to_window((param)->mlx_ptr, (param)->win_ptr, \
			(param)->img_ptr, 0, 0);
	print_info(param);
	return (0);
}
