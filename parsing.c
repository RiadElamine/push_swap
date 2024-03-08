/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 00:26:12 by relamine          #+#    #+#             */
/*   Updated: 2024/03/08 11:50:31 by relamine         ###   ########.fr       */
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
        return (free(arr), free(arr2), NULL);
    i = 0;
    j = 0;
    
    while (arr[i])
        tb[i++] = arr[j++];
    j = 0;
    while (arr2[j])
        tb[i++] = arr2[j++];
    return (free(arr), tb[i] = '\0', tb);
}

int parsing(int argc, char **argv)
{
    int     j;
    char    *list;

    if (argc >= 2)
    {
        j = 1;
        list = NULL;
        while (j < argc)
        {
            list = ft_strjoin(list, argv[j]);
            if (!list)
                return (free(list), perror("malloc failed"), 1);
            list = ft_strjoin(list, " ");
            if (!list)
                return (free(list), perror("malloc failed"), 1);
            j++;
        }
    }
    printf("%s", list);
    return (1);
}


//atoi
//list =NULL
//lstmap(str, atoi, del, list);
