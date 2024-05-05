/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:59:14 by relamine          #+#    #+#             */
/*   Updated: 2024/04/29 12:02:34 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort(t_list **lst, char *msg)
{
	t_list	*node;
	t_list	*tmp;

	if (!(*lst) || !(*lst)->next)
		return ;
	tmp = *lst;
	while (tmp->next)
	{
		if (tmp->next->next == NULL)
			node = tmp;
		tmp = tmp->next;
	}
	node->next = NULL;
	ft_lstadd_front(lst, tmp);
	write(1, msg, 4);
}

void	rra(t_list **lst)
{
	sort(lst, "rra\n");
}

void	rrb(t_list **lst)
{
	sort(lst, "rrb\n");
}

void	rrr(t_list **lst_a, t_list **lst_b)
{
	sort(lst_a, NULL);
	sort(lst_b, NULL);
	if (!(*lst_a) || !(*lst_b))
		return ;
	if (!(*lst_a)->next && !(*lst_b)->next)
		return ;
	write(1, "rrr\n", 4);
}
