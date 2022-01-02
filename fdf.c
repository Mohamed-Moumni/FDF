/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 15:58:54 by mmoumni           #+#    #+#             */
/*   Updated: 2022/01/02 20:45:29 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_stack(t_stack *stack, t_fdf *fdf)
{
	t_stack	*ptr;
	t_stack	*suiv;

	while (stack != NULL)
	{
		suiv = stack->next;
		free(stack->z);
		stack = suiv;
	}
	while (fdf->stack)
	{
		ptr = fdf->stack->next;
		free(fdf->stack);
		fdf->stack = ptr;
	}
}

void	init_camera(t_fdf *fdf)
{
	if (fdf->width >= 400)
		fdf->zoom = 1;
	else if (fdf->width >= 300)
		fdf->zoom = 5;
	else
		fdf->zoom = 20;
	fdf->x_pos = (WIDTH / 2) - (fdf->width / 2);
	fdf->y_pos = (HEIGHT / 2) - (fdf->height / 2);
	fdf->project = 1;
	fdf->def_ang = DEFAULT_ANG;
	fdf->altitude = 1;
}

void	fdf_init(t_fdf *fdf, char *filename, int *check_fd)
{
	t_stack	*stack;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		print_error(1);
	check_filename(filename);
	fdf->stack = read_map(fd, &fdf->height, &fdf->width, check_fd);
	if (*check_fd == -1)
		print_error(3);
	else if (*check_fd == -2)
		print_error(4);
	stack = fdf->stack;
	fdf->matrix = create_matrix(fdf, fdf->stack);
	free_stack(stack, fdf);
	fdf->stack = NULL;
	init_camera(fdf);
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIDTH, HEIGHT, "FDF");
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, WIDTH, HEIGHT);
}

int	main(int ac, char **av)
{
	t_fdf	*fdf;
	int		check_fd;

	if (ac == 2)
	{
		check_fd = 0;
		fdf = (t_fdf *)malloc(sizeof(t_fdf));
		fdf_init(fdf, av[1], &check_fd);
		free(fdf->stack);
		ft_draw(fdf);
		mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, WIDTH - 90, 0, \
				0xffffff, "By Rigor");
		mlx_hook(fdf->win_ptr, 2, 1L << 0, esc_close, fdf);
		mlx_hook(fdf->win_ptr, 17, 0L, close_win, fdf);
		mlx_loop(fdf->mlx_ptr);
	}
	else
		print_error(2);
	return (0);
}
