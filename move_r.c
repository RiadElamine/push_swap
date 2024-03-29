/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:58:55 by relamine          #+#    #+#             */
/*   Updated: 2024/03/29 21:41:45 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void sort(t_list **lst)
{
    t_list *node;
    

    if ((*lst)->next == NULL)
        return ;
    node = (*lst);
    (*lst) = (*lst)->next;
    node->next = NULL;
    ft_lstadd_back(lst, node);
}

void ra(t_list **lst)
{
    sort(lst);
    write(1, "ra\n", 3);
}

void rb(t_list **lst)
{
    sort(lst);
    write(1, "rb\n", 3);
}

void rr(t_list **lst_a, t_list **lst_b)
{
    sort(lst_a);
    sort(lst_b);
    write(1, "rr\n", 3);
}