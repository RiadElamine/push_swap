/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rr_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:59:14 by relamine          #+#    #+#             */
/*   Updated: 2024/05/04 00:33:02 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

static void	sort(t_list **lst)
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
}

void	rra(t_list **lst)
{
	sort(lst);
}

void	rrb(t_list **lst)
{
	sort(lst);
}

void	rrr(t_list **lst_a, t_list **lst_b)
{
	sort(lst_a);
	sort(lst_b);
}
