/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:50:38 by relamine          #+#    #+#             */
/*   Updated: 2024/03/13 17:52:52 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

 void ft_lstadd_front(t_list **lst, t_list *newlist)
{
    if (!lst || !newlist)
        return;
    newlist->next = *lst;
    *lst = newlist;
}
 void ft_lstclear(t_list *lst)
{
    t_list *nexlist;

    if (!lst)
		return ;
    while (lst)
    {
        nexlist = lst->next;
        free(lst);
        lst = nexlist;
    }     
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
void ft_lstmap_atoi(t_list **lst, char  *str,  int *is_error)
{
    t_list  *newlist;

    newlist = ft_lstnew(ft_atoi(str, is_error));
    if (!newlist)
        return (*is_error = 255, ft_lstclear(*lst));
    if (*is_error == 255 || ft_isalready_exist(*lst, newlist->content))
        return (*is_error = 255, free(newlist), ft_lstclear(*lst));
    ft_lstadd_back(lst, newlist);

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