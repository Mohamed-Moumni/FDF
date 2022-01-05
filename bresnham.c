/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresnham.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 12:37:49 by mmoumni           #+#    #+#             */
/*   Updated: 2022/01/05 21:50:23 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	compare(int a, int b)
{
	int	ret;

	if (a < b)
		ret = 1;
	else
		ret = -1;
	return (ret);
}

void	put_pixel(t_fdf *fdf, int x, int y)
{
	char	*addr;

	if ((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT))
	{
		fdf->img_data = mlx_get_data_addr(fdf->img_ptr \
				, &fdf->bpp, &fdf->size_line, &fdf->endian);
		addr = fdf->img_data + (y * fdf->size_line + x * (fdf->bpp / 8));
		*(unsigned int *)addr = fdf->color;
	}
}

t_param	*init_param(t_point *a, t_point *b)
{
	t_param	*param;

	param = (t_param *)malloc(sizeof(t_param));
	if (!param)
		return (NULL);
	param->dx = abs(b->x - a->x);
	param->sx = compare(a->x, b->x);
	param->dy = -abs(b->y - a->y);
	param->sy = compare(a->y, b->y);
	param->err = param->dx + param->dy;
	return (param);
}

void	bresnham(t_fdf *fdf, t_point *a, t_point *b)
{
	t_param	*param;

	param = init_param(a, b);
	while (1)
	{
		put_pixel(fdf, a->x, a->y);
		if (a->x == b->x && a->y == b->y)
			break ;
		param->e2 = 2 * param->err;
		if (param->e2 >= param->dy)
		{
			param->err += param->dy;
			a->x += param->sx;
		}	
		if (param->e2 <= param->dx)
		{
			param->err += param->dx;
			a->y += param->sy;
		}
	}
	free(a);
	free(b);
	free(param);
}
