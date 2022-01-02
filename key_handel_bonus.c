/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handel_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 15:13:07 by mmoumni           #+#    #+#             */
/*   Updated: 2022/01/02 17:26:38 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keys_bonus.h"

int	rot(int key, t_fdf *param)
{
    if (key == X)
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

int	key_zoom(int key, t_fdf *param)
{
	if (key == ZOOM_IN)
	{
		(param)->zoom += 2;
		param->x_pos -= 10;
		param->y_pos -= 10;
	}
	else if (key == ZOOM_OUT)
	{
		(param)->zoom -= 2;
		param->x_pos += 10;
		param->y_pos += 10;
	}
    return (0);
}

int	translate_map(int key, t_fdf *param)
{
	if (key == UP)
	{
		param->y_pos -= 20; 
	}
	else if (key == DOWN)
	{
		param->y_pos += 20;
	}
	else if (key == LEFT)
	{
		param->x_pos -= 20;
	}
	else if (key == RIGHT)
	{
		param->x_pos += 20;
	}
    return (0);
}

int	altitude_event(int key, t_fdf *param)
{
	if (key == PLUS_ALT)
	{
		param->altitude += 2;
	}
	else if (key == MINUS_ALT)
	{
		param->altitude -= 2;
	}
    return (0);
}

int	change_proj(int	key, t_fdf *param)
{
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

int event_key(int key, t_fdf *param)
{
	key_zoom(key, param);
	translate_map(key, param);
	altitude_event(key,param);
	change_proj(key, param);
	rot(key, param);
	mlx_clear_window((param)->mlx_ptr, (param)->win_ptr);
	mlx_destroy_image(param->mlx_ptr,param->img_ptr);
	param->img_ptr = mlx_new_image(param->mlx_ptr, WIDTH, HEIGHT);
	ft_draw((param));
	mlx_put_image_to_window((param)->mlx_ptr, (param)->win_ptr, (param)->img_ptr, 0, 0);
	return (0);
}