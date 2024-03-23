/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:59:14 by relamine          #+#    #+#             */
/*   Updated: 2024/03/23 00:05:11 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void sort(t_list **lst)
{
    t_list *node;
    t_list	*tmp;

    if ((*lst)->next == NULL)
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

void rra(t_list **lst)
{
    sort(lst);
    write(1, "rra\n", 4);
}

void rrb(t_list **lst)
{
    sort(lst);
    write(1, "rrb\n", 4);
}

void rrr(t_list **lst_a, t_list **lst_b)
{
    sort(lst_a);
    sort(lst_b);
    write(1, "rrr\n", 4);
}