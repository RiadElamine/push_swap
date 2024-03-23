/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:50:38 by relamine          #+#    #+#             */
/*   Updated: 2024/03/22 20:44:18 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static int ft_isempty(char *str)
{
    while (*str == ' ')
        str++;
    if (*str == '\0')
        return (1);
    return (0);
}

char**    ft_oned_array(int argc, char **argv)
{
    int     j;
    char    *list;
    char    **tod_array;

    j = 1;
    list = NULL;
    while (j < argc)
    {
        if (ft_isempty(argv[j]))
            return (NULL);
        list = ft_strjoin(list, argv[j]);
        if (!list)
            return (NULL);
        list = ft_strjoin(list, " ");
        if (!list)
            return (NULL);
        j++;
    }
    tod_array = ft_split(list);
    return (free(list), tod_array);
}

static int  ft_opt_isdigit(char **twod_array, int i, int j)
{
    char    c;
    char    n;

    c = twod_array[i][j];
    n = twod_array[i][j + 1];
    if ((c == '-' || c == '+') && !(n >= '0' && n <= '9'))
        return (255);
    if ((c >= '0' && c <= '9') && (n == '-' || n == '+'))
        return(255);
    if (!((c >= '0' && c <= '9') || (c == '-' || c == '+')))
        return(255);
    return (0);
}
int ft_err_conv_lst(char **twod_array, t_list **head)
{
    int    i;
    int     j;
    int     is_error;

    i = 0;
    is_error = 0;
    while (twod_array[i])
    {
        j = 0;
        while (twod_array[i][j])
        {
            if (ft_opt_isdigit(twod_array, i, j) == 255)
                return (free(twod_array[i]), 255);
            j++;
        }
        ft_lstmap_atoi(head, twod_array[i], &is_error);
        free(twod_array[i++]);
        if (is_error == 255)
            return (is_error);
    }
    return (0);
}

int  ft_isalready_exist(t_list   *list, int  content)
{
    while (list)
    {
        if (list->content == content)
            return (1);
        list = list->next;
    }
    return (0);
}