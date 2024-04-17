/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:38:29 by relamine          #+#    #+#             */
/*   Updated: 2024/04/17 10:18:31 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_push_a(t_list **stack_a, t_list **stack_b, t_list *lst)
{
    if (lst->part == 1)
    {
        while ((*stack_b) && (*stack_b)->content != lst->content)
        {
            (*stack_b)->part = 2;
            rb(stack_b);
        }
    }
    else if (lst->part == 2)
    {
        while ((*stack_b)->content != lst->content)
        {
            (*stack_b)->part = 1;
            rrb(stack_b);
        }
    }
    pa(stack_a, stack_b);
}
static void  ft_count(t_list *lst, int *i, t_list *max, int part)
{
    if (part == 2)
    { 
        if (!max->next)
            *i = 0;
        while (max->next && max->content != max->next->content && max->next->part == part)
        {
            *i = *i + 1;
            max = max->next;
        }
    }
    else
    {
        if (lst->content == max->content)
            *i = 0;
        while (lst && lst->content != max->content && lst->next->part == part)
        {
            *i = *i + 1;
            lst = lst->next;
        }
    }
}
static t_list  *ft_get_position(int *ismax, int *imax, t_list *tmp_max, t_list **stack_b)
{
    t_list  *get_smax;
    int smax;

    smax = tmp_max->index - 1;
    if ((*stack_b)->next != NULL)
    {
        get_smax = *stack_b;
        while (get_smax && get_smax->index != smax)
            get_smax =  get_smax->next;
        ft_count(*stack_b, ismax, get_smax, get_smax->part);
        ft_count(*stack_b, imax, tmp_max, tmp_max->part);
        return (get_smax);
    }
    return (NULL);
}
static void ft_organize_a(t_list **stack_a, t_list **stack_b, t_list *smax, int b)
{
    int j;
    int ismax;
    int imax;
    var v;

    j = 0;
    while (j < b)
    {   
        ismax = -1;
        imax = -1;
        ft_get_max(stack_b, &v, b - j);
        smax = ft_get_position(&ismax, &imax, v.tmp_max, stack_b);
        if (ismax < imax && ismax != -1)
        {
            ft_push_a(stack_a, stack_b, smax);
            j++;
        }
        ft_push_a(stack_a, stack_b, v.tmp_max);
        j++;
        if (ismax < imax && ismax != -1)
            sa(*stack_a);
    }
}
void ft_push_to_a(t_list **stack_a, t_list **stack_b, int argc)
{
    t_list *smax;
    ft_organize_a(stack_a, stack_b, smax, argc);
}