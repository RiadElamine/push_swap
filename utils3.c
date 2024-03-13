/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:59:33 by relamine          #+#    #+#             */
/*   Updated: 2024/03/13 18:01:57 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

 size_t  ft_column_size(char   *str)
{
    size_t  column_len;

    column_len = 0;
    while (str[column_len] && str[column_len] != ' ')
        column_len++;
    return (column_len);
}
 char **ft_strsplit(size_t rows, char **s2, char *s1)
{
    size_t  j;
    size_t  columns;
    size_t  i;

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
    return(s2[i] = NULL, s2);
}