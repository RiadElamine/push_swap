/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:15:35 by relamine          #+#    #+#             */
/*   Updated: 2024/04/28 16:51:49 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_checker_sort(t_list **stack_a, int argc, int new_stdout)
{
	int		i;
	t_list	*tmp;

	i = ft_lstsize(*stack_a);
	if (i < argc)
		return (write(new_stdout, "KO\n", 3), (void)0);
	ft_index(stack_a, argc);
	i = 1;
	tmp = *stack_a;
	while (tmp)
	{
		if ((tmp)->index != i)
			return (write(new_stdout, "KO\n", 3), (void)0);
		i++;
		(tmp) = (tmp)->next;
	}
	write(new_stdout, "OK\n", 3);
}

void	ft_moveadd_front(t_buffer **lst, t_buffer *newlist)
{
	if (!lst || !newlist)
		return ;
	newlist->next = *lst;
	*lst = newlist;
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