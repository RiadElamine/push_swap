/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:11:08 by relamine          #+#    #+#             */
/*   Updated: 2024/04/17 10:21:10 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_check_sort(t_list **list, int size)
{
    t_list  *tmp;
    int check_sort;

    tmp = *list;
    check_sort = 1;
    while (--size)
    {
        if (tmp->content > tmp->next->content)
            check_sort = 0;
        tmp = tmp->next ;
    }
    return (check_sort);
}

void ft_sort_three(t_list **list, int size_list)
{
    t_list  *tmp;

    if (ft_check_sort(list, size_list))
        return ;
    tmp = (*list);
    if (size_list  == 2 )
        sa(*list);
    else
    {
        if (tmp->content < tmp->next->next->content)
            sa(*list);
        if (tmp->content > tmp->next->next->content) 
            ra(list);
        ft_sort_three(list, size_list);
    }
    return ;
}

void ft_sort_four(t_list **lsta, t_list **lstb)
{
    var v;

    if (ft_check_sort(lsta, 4))
        return;
    ft_get_min(lsta, &v, 4);
    if (v.imin == 2)
        sa(*lsta);
    if (v.imin == 3)
    {
        ra(lsta);
        ra(lsta);
    }
    else if (v.imin == 4)
        rra(lsta);
    pb(lsta, lstb);
    ft_sort_three(lsta, 3);
    pa(lsta, lstb);
}
void ft_sort_five(t_list **lsta, t_list **lstb)
{
    var v;

    if (ft_check_sort(lsta, 5))
        return;
    ft_get_min(lsta, &v, 5);
    if (v.imin == 2)
        sa(*lsta);
    if (v.imin == 3)
    {
        ra(lsta);
        ra(lsta);
    }
    else if ((v.imin == 5 || v.imin == 4) && (!(v.imin == 1 || v.imin == 1)))
    {
        if (v.imin == 4 || v.imin == 4 )
            rra(lsta);
        rra(lsta);
    }
    pb(lsta, lstb);
    ft_sort_four(lsta, lstb);
    pa(lsta, lstb);
}  


void ft_sort_big_nbr(t_list *stack_a, t_list *stack_b, int argc)
{
    int chunks;

    chunks = 5;
    if (argc >= 500)
        chunks = 9;
    ft_push_to_b(&stack_a, &stack_b, argc, chunks);
    ft_sort_five(&stack_a, &stack_b);
    ft_push_to_a(&stack_a, &stack_b, argc - 5);
    // ft_index(&stack_a, argc);
}
