/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 12:40:11 by mmoumni           #+#    #+#             */
/*   Updated: 2022/01/05 22:42:19 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	check_line_error(int width, int i, int *check_fd, char **split)
{
	free_tab(split);
	if (width > i)
	{
		*check_fd = -2;
		return (1);
	}
	return (0);
}

int	get_line_info(char *line, t_stack **stack, int *width, int *check_fd)
{
	int		i;
	char	**split;
	char	**sec_split;
	int		j;	

	split = ft_split(line, ' ');
	i = 0;
	j = 0;
	while (split[i] != NULL)
	{
		sec_split = ft_split(split[i], ',');
		if (fill_stack(sec_split, stack))
		{
			free_tab(sec_split);
			free_tab(split);
			*check_fd = -1;
			return (1);
		}
		free_tab(sec_split);
		j++;
		i++;
	}
	if (check_line_error(*width, i, check_fd, split))
		return (1);
	return (0);
}

t_stack	*read_map(int fd, int *height, int *width, int *check_fd)
{
	char	*tmp;
	t_stack	*stack;
	int		i;
	int		check;

	i = 0;
	tmp = get_next_line(fd);
	if (tmp == NULL)
		print_error(1);
	stack = NULL;
	*width = ft_words(tmp, ' ');
	while (tmp != NULL)
	{
		i++;
		check = get_line_info(tmp, &stack, width, check_fd);
		if (check != 0)
			return (NULL);
		free(tmp);
		tmp = get_next_line(fd);
	}
	*height = i;
	free(tmp);
	close(fd);
	return (stack);
}
