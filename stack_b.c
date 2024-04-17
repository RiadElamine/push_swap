/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:45:07 by relamine          #+#    #+#             */
/*   Updated: 2024/04/17 10:18:43 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_organize_b(var_a *vp, int a, int b)
{
    int i;
    int c;
    t_list *tmp;

    i = 0;
    c = 0;
    tmp = (*(*vp).node_a);
    while (++i <= (*vp).argc)
    {
        if (tmp->index >= a && tmp->index <= b )
        {
            pb((*vp).node_a, (*vp).node_b);
            (*(*vp).node_b)->part = 1;
            if ((*(*vp).node_b)->index > (a + ((b - a) / 2)))
            {
                (*(*vp).node_b)->part = 2;
                rb((*vp).node_b);
            }
            c++;
        }
        else
            ra((*vp).node_a);
        tmp = (*(*vp).node_a);
    }
    (*vp).argc = (*vp).argc - c;
}

void ft_push_to_b(t_list **stack_a, t_list **stack_b, int argc, int chunks)
{
    int a;
    var_a vp;
    int i;
    int j;

    vp.node_a = stack_a;
    vp.node_b = stack_b;
    vp.argc = argc;
    a = (argc - 5) / chunks;
    i = 1;
    j = 1;
    while (j < chunks)
    {
        ft_organize_b(&vp, i, a * j);
        i += a;
        j++;
    }
    ft_organize_b(&vp, i, argc - 5);
}
