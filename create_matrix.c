/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 22:37:54 by mmoumni           #+#    #+#             */
/*   Updated: 2022/01/02 17:10:41 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_data(t_matrix *matrix, t_stack **stack, t_fdf *fdf)
{
	int	width;

	width = fdf->width;
	while (width--)
	{
		matrix[width].z.altitude = (*stack)->z->altitude;
		matrix[width].z.color = (*stack)->z->color;
		(*stack) = (*stack)->next;
	}
}

t_matrix	**create_matrix(t_fdf *fdf, t_stack *stack)
{
	t_matrix	**matrix;
	int			height;
	int			width;

	height = fdf->height;
	width = fdf->width;
	matrix = (t_matrix **)malloc(sizeof(t_matrix *) * height);
	if (!matrix)
		return (NULL);
	while (height--)
	{
		matrix[height] = (t_matrix *)malloc(sizeof(t_matrix) * (width));
		if (!matrix[height])
			return (NULL);
		fill_data(matrix[height], &stack, fdf);
	}
	return (matrix);
}
