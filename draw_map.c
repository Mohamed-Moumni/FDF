/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 11:21:35 by mmoumni           #+#    #+#             */
/*   Updated: 2022/01/02 20:04:25 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*projection(t_point *p, t_fdf *fdf)
{
	p->x *= fdf->zoom;
	p->y *= fdf->zoom;
	x_rotation(&p->x, &p->y, &p->z, fdf->alpha);
	y_rotation(&p->x, &p->y, &p->z, fdf->beta);
	z_rotation(&p->x, &p->y, &p->z, fdf->teta);
	if (fdf->project == 1)
		iso(&p->x, &p->y, p->z, fdf->def_ang);
	p->x += fdf->x_pos;
	p->y += fdf->y_pos;
	return (p);
}

void	set_xpixel(t_fdf *fdf, int x, int y)
{
	if (fdf->matrix[y][x].z.color == -1)
	{
		if (fdf->matrix[y][x].z.altitude != 0)
			fdf->color = 0xff0000;
		else
			fdf->color = 0xffffff;
	}
	else
		fdf->color = fdf->matrix[y][x].z.color;
	bresnham(fdf, projection(point_init(x, y, fdf), fdf) \
			, projection(point_init(x + 1, y, fdf), fdf));
}

void	set_ypixel(t_fdf *fdf, int x, int y)
{
	if (fdf->matrix[y][x].z.color == -1)
	{
		if (fdf->matrix[y][x].z.altitude != 0)
			fdf->color = 0xff0000;
		else
			fdf->color = 0xffffff;
	}
	else
		fdf->color = fdf->matrix[y][x].z.color;
	bresnham(fdf, projection(point_init(x, y, fdf), fdf) \
			, projection(point_init(x, y + 1, fdf), fdf));
}

void	ft_draw(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			if (x < fdf->width - 1)
				set_xpixel(fdf, x, y);
			if (y < fdf->height - 1)
				set_ypixel(fdf, x, y);
			x++;
		}
		y++;
	}
}
