/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 12:09:31 by mmoumni           #+#    #+#             */
/*   Updated: 2022/01/02 16:35:55 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include "get_next_line.h"

# define WIDTH 1000
# define HEIGHT 768
# define DEFAULT_ANG 0.523599
typedef struct s_z
{
	int	altitude;
	int	color;
}	t_z;

typedef struct s_stack
{
	t_z				*z;
	struct s_stack	*next;
}	t_stack;

typedef struct s_matrix
{
	t_z z;
}	t_matrix;

typedef struct s_fdf
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*img_data;
	t_matrix	**matrix;
	t_stack		*stack;
	int			width;
	int			height;
	int			zoom;
	int			color;
	int			x_pos;
	int			y_pos;
	int			bpp;
	int			size_line;
	int			endian;
	int			altitude;
	int			project;
	int			rot;
	double		def_ang;
	double		alpha;
	double		beta;
	double		teta;
}	t_fdf;

typedef struct s_param
{
	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	err;
	int	e2;
}	t_param;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

int			ft_atoi_hex(char *str);
void		bresnham(t_fdf *data, t_point *a, t_point *b);
void		ft_draw(t_fdf *fdf);
void		iso(int *x, int *y, int z, double);
t_stack		*read_map(int fd, int *height, int *width, int *check_fd);
t_point		*point_init(int x, int y, t_fdf *fdf);
t_point		*projection(t_point *p, t_fdf *fdf);
t_matrix	**create_matrix(t_fdf *fdf, t_stack *stack);
int			ft_words(const char *s, char c);
char		**ft_split(char *s, char c);
int			ft_atoi(const char *str);
void		stack_add_front(t_stack **stack, t_stack *new);
int			key_handel(int key, t_fdf *param);
int			translate_map(int key, t_fdf *param);
int			key_zoom(int key, t_fdf *param);
void		print_error(int error);
int			fill_stack(char **sec_split, t_stack **stack);
void		x_rotation(int *x, int *y, int *z, double teta);
void		y_rotation(int *x, int *y, int *z, double teta);
void		z_rotation(int *x, int *y, int *z, double teta);
int			event_key(int key, t_fdf *param);
void		screen_info(t_fdf *fdf);
int			rot(int key, t_fdf *param);
int			esc_close(int key, t_fdf *param);
int			close_win(void *param);

#endif
