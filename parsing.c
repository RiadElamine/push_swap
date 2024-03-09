/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 00:26:12 by relamine          #+#    #+#             */
/*   Updated: 2024/03/09 11:50:25 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <libc.h>

static size_t  ft_strlen(char  *str)
{
    size_t  i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

static char    *ft_strdup(char *str)
{
    char    *tb;
    int     i;
    int     j;

    tb = malloc(ft_strlen(str) + 1);
    if (!tb)
        return (NULL);
    i = 0;
    j = 0;
    while (str[j])
        tb[i++] = str[j++];
    return (tb[i] = '\0', tb);
}

static char    *ft_strjoin(char *arr, char *arr2)
{
    char    *tb;
    int     i;
    int     j;

    if (!arr)
        return (ft_strdup(arr2));
    tb = malloc(ft_strlen(arr)+ ft_strlen(arr2) + 1);
    if(!tb)
        return (NULL);
    i = 0;
    j = 0;
    while (arr[i])
        tb[i++] = arr[j++];
    j = 0;
    while (arr2[j])
        tb[i++] = arr2[j++];
    return (free(arr), tb[i] = '\0', tb);
}
static char*    ft_oned_array(int argc, char **argv)
{
    int     j;
    char    *list;

    j = 1;
    list = NULL;
    while (j < argc)
    {
        list = ft_strjoin(list, argv[j]);
        if (!list)
            return (perror("malloc failed"), NULL);
        list = ft_strjoin(list, " ");
        if (!list)
            return (perror("malloc failed"), NULL);
        j++;
    }
    return (list);
}
static size_t  ft_row_size(char   *str)
{
    size_t  row_len;

    row_len = 0;
    while (*str)
    {
        while (*str == ' ')
            str++;
        if(!*str)
            break;
        while (*str != ' ')
            str++;
        row_len++;
    }
    return (row_len);
}

static size_t  ft_column_size(char   *str)
{
    size_t  column_len;

    column_len = 0;
    while (str[column_len] && str[column_len] != ' ')
        column_len++;
    return (column_len);
}
static char **ft_strsplit(size_t rows, char **s2, char *s1)
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
static char **ft_split(char *s1)
{
    char    **s2;
    size_t  rows;
    
    rows = ft_row_size(s1);
    s2 = malloc((rows + 1)* sizeof(char *));
    if (!s2)
        return (NULL);
    return (ft_strsplit(rows, s2, s1), s2);
}
static int  ft_isdigit(char c)
{
    return ((c == '-' || c == '+') || (c >= '0' && c <= '9'));
}
int ft_parsing(int argc, char **argv)
{
    char    *list;
    char    **twod_array;

    if (argc <= 1)
        return (-1);
    list = ft_oned_array(argc, argv);
    if (!list)
        return (255);
    twod_array = ft_split(list); 

    int    i = 0;
    int     j;
    while (twod_array[i])
    {
        j = 0;
        while (twod_array[i][j])
        {
            if (!ft_isdigit(twod_array[i][j]))
            {
                return(write(2, "Error", 5), 255);
            }
            if (twod_array[i][j + 1] == '+' || twod_array[i][j + 1] == '-')
                return(write(2, "Error", 5), 255);
            j++;
        }
        i++;
    }

    return (0);
}


//atoi
//list =NULL
//lstmap(str, atoi, del, list);



