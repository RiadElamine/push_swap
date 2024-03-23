/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:55:44 by relamine          #+#    #+#             */
/*   Updated: 2024/03/22 21:55:23 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list   *ft_lstnew(int content)
{
    t_list *newlist;

    newlist = malloc(sizeof(t_list));
    if(!newlist)
        return (write(2, "Error\n", 6), NULL);
    newlist->content = content;
    newlist->next = NULL;
    return (newlist);
}
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
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!*lst)
	{
		(*lst) = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
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
