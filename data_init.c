/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:35:24 by mmoumni           #+#    #+#             */
/*   Updated: 2022/01/02 17:10:39 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*point_init(int x, int y, t_fdf *fdf)
{
	t_point	*p;

	p = (t_point *)malloc(sizeof(t_point));
	if (!p)
		return (NULL);
	p->x = x;
	p->y = y;
	p->z = fdf->matrix[y][x].z.altitude * fdf->altitude;
	return (p);
}
