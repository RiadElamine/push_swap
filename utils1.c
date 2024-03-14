/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:50:38 by relamine          #+#    #+#             */
/*   Updated: 2024/03/14 00:25:59 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int ft_isempty(char *str)
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
    return (ft_split(list));
}

int  ft_opt_isdigit(char c)
{
    return ((c == '-' || c == '+') || (c >= '0' && c <= '9'));
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
            if ((twod_array[i][j] == '-' || twod_array[i][j] == '+') && !ft_opt_isdigit(twod_array[i][j+1]))
                return (write(2, "Error\n", 6), 255);
            if (!ft_opt_isdigit(twod_array[i][j]))
                return(write(2, "Error\n", 6), 255);
            if (twod_array[i][j + 1] == '+' || twod_array[i][j + 1] == '-')
                return(write(2, "Error\n", 6), 255);
            j++;
        }
        ft_lstmap_atoi(head, twod_array[i], &is_error);
        if (is_error == 255)
            return (write(2, "Error\n", 6), is_error);
        i++;
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