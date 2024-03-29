/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:57:57 by relamine          #+#    #+#             */
/*   Updated: 2024/03/29 21:42:28 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void sort(t_list *lst)
{
    int value;

    if (lst->next == NULL)
        return ;
    value = lst->content;
    lst->content = lst->next->content;
    lst->next->content = value;
}

void sa(t_list *lst)
{
    sort(lst);
    write(1, "sa\n", 3);
}

void sb(t_list *lst)
{
    sort(lst);
    write(1, "sb\n", 3);
}

void ss(t_list *lst_a, t_list *lst_b)
{
    sort(lst_a);
    sort(lst_b);
    write(1, "ss\n", 3);
}