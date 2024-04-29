/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:59:33 by relamine          #+#    #+#             */
/*   Updated: 2024/04/28 09:21:57 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_row_size(char *str)
{
	size_t	row_len;

	row_len = 0;
	while (*str)
	{
		while (*str == ' ')
			str++;
		if (!*str)
			break ;
		while (*str != ' ')
			str++;
		row_len++;
	}
	return (row_len);
}

static size_t	ft_column_size(char *str)
{
	size_t	column_len;

	column_len = 0;
	while (str[column_len] && str[column_len] != ' ')
		column_len++;
	return (column_len);
}

static char	**ft_strsplit(size_t rows, char **s2, char *s1)
{
	size_t	j;
	size_t	columns;
	size_t	i;

	i = 0;
	while (i < rows)
	{
		while (*s1 == ' ')
			s1++;
		columns = ft_column_size(s1);
		s2[i] = malloc(columns + 1);
		if (!s2[i])
		{
			while (i >= 0)
				free(s2[--i]);
			return (free(s2), NULL);
		}
		j = 0;
		while (j < columns)
			s2[i][j++] = *(s1++);
		s2[i][j] = '\0';
		i++;
	}
	return (s2[i] = NULL, s2);
}

char	**ft_split(char *s1)
{
	char	**s2;
	size_t	rows;

	rows = ft_row_size(s1);
	s2 = malloc((rows + 1) * sizeof(char *));
	if (!s2)
		return (NULL);
	return (ft_strsplit(rows, s2, s1), s2);
}
