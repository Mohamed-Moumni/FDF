/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:59:13 by mmoumni           #+#    #+#             */
/*   Updated: 2021/12/23 20:42:23 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include<stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
int		get_ft_strlen(char	*str);
char	*get_ft_strdup(char *str);
char	*get_ft_strchr(char *s, int c);
char	*get_ft_strjoin(char *s1, char *s2);
#endif