/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:15:35 by relamine          #+#    #+#             */
/*   Updated: 2024/05/04 01:04:35 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

void	ft_checker_sort(t_list **stack_a, int argc)
{
	int		i;
	t_list	*tmp;

	i = ft_lstsize(*stack_a);
	if (i < argc)
		return (write(1, "KO\n", 3), (void)0);
	ft_index(stack_a, argc);
	i = 1;
	tmp = *stack_a;
	while (tmp)
	{
		if ((tmp)->index != i)
			return (write(1, "KO\n", 3), (void)0);
		i++;
		(tmp) = (tmp)->next;
	}
	write(1, "OK\n", 3);
}

void	ft_moveadd_back(t_buffer **lst, t_buffer *new)
{
	t_buffer	*tmp;

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

void	ft_moveclear(t_buffer *lst)
{
	t_buffer	*nexlist;

	if (!lst)
		return ;
	while (lst)
	{
		nexlist = lst->next;
		free(lst);
		lst = nexlist;
	}
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
