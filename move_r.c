/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:58:55 by relamine          #+#    #+#             */
/*   Updated: 2024/04/17 05:56:17 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void sort(t_list **lst, char *msg)
{
    t_list *node;
    

    if ((*lst)->next == NULL)
        return ;
    node = (*lst);
    (*lst) = (*lst)->next;
    node->next = NULL;
    ft_lstadd_back(lst, node);
    write(1, msg, 3);
}

void ra(t_list **lst)
{
    sort(lst, "ra\n");
}

void rb(t_list **lst)
{
    sort(lst, "rb\n");
}

void rr(t_list **lst_a, t_list **lst_b)
{
    sort(lst_a, NULL);
    sort(lst_b, NULL);
    if ((*lst_a)->next == NULL && (*lst_b)->next == NULL)
        return ;
    write(1, "rr\n", 3);
}