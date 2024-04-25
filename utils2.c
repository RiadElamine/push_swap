/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:55:44 by relamine          #+#    #+#             */
/*   Updated: 2024/04/19 12:40:55 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*newlist;

	newlist = malloc(sizeof(t_list));
	if (!newlist)
		return (write(2, "Error\n", 6), NULL);
	newlist->content = content;
	newlist->next = NULL;
	return (newlist);
}

void	ft_lstadd_front(t_list **lst, t_list *newlist)
{
	if (!lst || !newlist)
		return ;
	newlist->next = *lst;
	*lst = newlist;
}

void	ft_lstclear(t_list *lst)
{
	t_list	*nexlist;

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

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
