/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 09:09:56 by mbabela           #+#    #+#             */
/*   Updated: 2021/12/27 14:37:58 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_words(const char *s, char c)
{
	int	i;

	i = 0;
	while (*s != '\0')
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			i++;
		s++;
	}
	return (i);
}

static int	word_size(const char *s, char c)
{
	int	i;

	i = 0;
	while (*(s + i) != '\0' && *(s + i) != c)
	{
		i++;
	}
	return (i);
}

static char	*fill_str(char *lil_str, const char *s, char c)
{
	int	i;

	i = 0;
	while (*s != '\0' && *s != c)
	{
		*(lil_str + i) = *s;
		i++;
		s++;
	}
	*(lil_str + i) = '\0';
	return (lil_str);
}

static void	*free_f(char **str, int i)
{
	while (i >= 0)
	{
		free(str + i);
		i--;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char *s, char c)
{
	char	**tab;
	int		i;
	int		words;

	if (s == NULL)
		return (NULL);
	words = ft_words(s, c);
	tab = (char **)malloc(sizeof(char *) * (words + 1));
	if (tab == 0)
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*s == c && *s != '\0')
			s++;
		*(tab + i) = (char *)malloc(sizeof(char) * (word_size((s), c) + 1));
		if (*(tab + i) == 0)
			return (free_f(tab, i));
		fill_str(*(tab + i), s, c);
		while (*s != c && *s != '\0')
			s++;
		i++;
	}
	*(tab + i) = 0;
	return (tab);
}
