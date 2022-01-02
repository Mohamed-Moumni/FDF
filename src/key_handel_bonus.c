/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handel_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 15:13:07 by mmoumni           #+#    #+#             */
/*   Updated: 2022/01/01 20:09:44 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// int	rotation(int key, t_fdf *param)
// {
// 	if (key == 15)
// 	{
// 		param->teta += 0.2;
// 	}
// 	else
// 		return (0);
// 	mlx_clear_window((param)->mlx_ptr, (param)->win_ptr);
// 	mlx_destroy_image(param->mlx_ptr,param->img_ptr);
// 	param->img_ptr = mlx_new_image(param->mlx_ptr, WIDTH, HEIGHT);
// 	ft_draw(param);
// 	mlx_put_image_to_window((param)->mlx_ptr, (param)->win_ptr, (param)->img_ptr, 0, 0);
// 	screen_info(param);
// 	return(0);
// }

// int	rot(int key, t_fdf *param)
// {
// 	if (key == 7)
// 	{
// 		param->rot = 1;
// 		param->ang1 -= 0.2;
// 	}
// 	else if (key == 16)
// 	{
// 		param->rot = 2;
// 		param->ang2 -= 0.2;

// 	}
// 	else if (key == 6)
// 	{
// 		param->rot = 3;
// 		param->ang3 -= 0.2;
// 	}
// 	else
// 		return (0);
// 	mlx_clear_window((param)->mlx_ptr, (param)->win_ptr);
// 	mlx_destroy_image(param->mlx_ptr,param->img_ptr);
// 	param->img_ptr = mlx_new_image(param->mlx_ptr, WIDTH, HEIGHT);
// 	ft_draw((param));
// 	mlx_put_image_to_window((param)->mlx_ptr, (param)->win_ptr, (param)->img_ptr, 0, 0);
// 	screen_info(param);
// 	return (0);
// }
// int	key_handel(int key, t_fdf *param)
// {
// 	if (key == 53)
// 	{
// 		mlx_destroy_window((param)->mlx_ptr, (param)->win_ptr);
// 		free((param)->mlx_ptr);
// 		exit(0);
// 	}
// 	return (0);
// }

// int	key_zoom(int key, t_fdf *param)
// {
// 	if (key == 69)
// 	{
// 		(param)->zoom += 2;
// 		param->x_pos -= 10;
// 		param->y_pos -= 10;
// 	}
// 	else if (key == 78)
// 	{
// 		((param))->zoom -= 2;
// 		param->x_pos += 10;
// 		param->y_pos += 10;
// 	}
// 	else
// 		return (0);
// 	mlx_clear_window((param)->mlx_ptr, (param)->win_ptr);
// 	mlx_destroy_image(param->mlx_ptr,param->img_ptr);
// 	param->img_ptr = mlx_new_image(param->mlx_ptr, WIDTH, HEIGHT);
// 	ft_draw((param));
// 	mlx_put_image_to_window((param)->mlx_ptr, (param)->win_ptr, (param)->img_ptr, 0, 0);
// 	screen_info(param);
// 	return (0);
// }

// int	translate_map(int key, t_fdf *param)
// {
// 	if (key == 126)
// 	{
// 		param->y_pos -= 20; 
// 	}
// 	else if (key == 125)
// 	{
// 		param->y_pos += 20;
// 	}
// 	else if (key == 123)
// 	{
// 		param->x_pos -= 20;
// 	}
// 	else if (key == 124)
// 	{
// 		param->x_pos += 20;
// 	}
// 	else
// 		return (0);
// 	mlx_clear_window((param)->mlx_ptr, (param)->win_ptr);
// 	mlx_destroy_image(param->mlx_ptr,param->img_ptr);
// 	param->img_ptr = mlx_new_image(param->mlx_ptr, WIDTH, HEIGHT);
// 	ft_draw((param));
// 	mlx_put_image_to_window((param)->mlx_ptr, (param)->win_ptr, (param)->img_ptr, 0, 0);
// 	screen_info(param);
// 	return (0);
// }

// int	altitude_event(int key, t_fdf *param)
// {
// 	if (key == 35)
// 	{
// 		param->altitude += 2;
// 	}
// 	else if (key == 46)
// 	{
// 		param->altitude -= 2;
// 	}
// 	else
// 		return (0);
// 	mlx_clear_window((param)->mlx_ptr, (param)->win_ptr);
// 	mlx_destroy_image(param->mlx_ptr,param->img_ptr);
// 	param->img_ptr = mlx_new_image(param->mlx_ptr, WIDTH, HEIGHT);
// 	ft_draw((param));
// 	mlx_put_image_to_window((param)->mlx_ptr, (param)->win_ptr, (param)->img_ptr, 0, 0);
// 	screen_info(param);
// 	return (0);
// }
// int	change_proj(int	key, t_fdf *param)
// {
// 	if (key == 85)
// 	{
// 		param->project = 1;
// 	}
// 	else if (key == 84)
// 	{
// 		param->project = 0;
// 	}
// 	else
// 		return (0);
// 	mlx_clear_window((param)->mlx_ptr, (param)->win_ptr);
// 	mlx_destroy_image(param->mlx_ptr,param->img_ptr);
// 	param->img_ptr = mlx_new_image(param->mlx_ptr, WIDTH, HEIGHT);
// 	ft_draw((param));
// 	mlx_put_image_to_window((param)->mlx_ptr, (param)->win_ptr, (param)->img_ptr, 0, 0);
// 	screen_info(param);
// 	return (0);
// }
// int event_key(int key, t_fdf *param)
// {
// 	key_zoom(key, param);
// 	translate_map(key, param);
// 	rotation(key, param);
// 	altitude_event(key,param);
// 	change_proj(key, param);
// 	rot(key, param);
// 	return (0);
// }