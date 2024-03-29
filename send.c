/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 00:43:00 by relamine          #+#    #+#             */
/*   Updated: 2024/03/29 21:43:29 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push(t_list **src , t_list **dest)
{
    t_list *send;
    t_list *next_send;

    send = (*src);
    next_send = (*dest);
    (*src) = (*src)->next;
    (*dest) = send;
    send->next = next_send;
}

void pb(t_list **lsta , t_list **lstb)
{
    push(lsta, lstb);
    write(1, "pb\n", 3);
}

void pa(t_list **lsta , t_list **lstb)
{
    push(lstb, lsta);
    write(1, "pa\n", 3);
}
//protect lstb and lsta