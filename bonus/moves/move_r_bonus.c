/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_r_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:58:55 by relamine          #+#    #+#             */
/*   Updated: 2024/05/04 01:21:52 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

static void	sort(t_list **lst)
{
	t_list	*node;

	if (!(*lst) || !(*lst)->next)
		return ;
	node = (*lst);
	(*lst) = (*lst)->next;
	node->next = NULL;
	ft_lstadd_back(lst, node);
}

void	ra(t_list **lst)
{
	sort(lst);
}

void	rb(t_list **lst)
{
	sort(lst);
}

void	rr(t_list **lst_a, t_list **lst_b)
{
	sort(lst_a);
	sort(lst_b);
}
