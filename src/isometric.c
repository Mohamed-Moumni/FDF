/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 20:40:27 by mmoumni           #+#    #+#             */
/*   Updated: 2022/01/01 14:54:54 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	iso(int *x, int *y, int z, double teta)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(teta);
	*y = (previous_x + previous_y) * sin(teta) - z;
}

// void	x_rotation(int *x, int *y, int *z, double teta)
// {
// 	*y = *y * cos(teta) + *z * sin(teta);
// 	*z = -(*y)*sin(teta) + *z * (cos(teta));
// }

// void	y_rotation(int *x, int *y, int *z, double teta)
// {
// 	*x = *x * cos(teta) + *z * sin(teta);
// 	*z = -(*x) * sin(teta) + *z * (cos(teta));
// }

// void	z_rotation(int *x, int *y, int *z, double teta)
// {
// 	*x = *x * cos(teta) - *y * sin(teta);
// 	*y = (*x) * sin(teta) + *y * (cos(teta));
// }