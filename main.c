/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 00:19:27 by relamine          #+#    #+#             */
/*   Updated: 2024/04/17 10:21:00 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void f()
{
    system("leaks push_swap");
}

static void ft_index(t_list **stack_a, int argc)
{
    t_list *tmp;
    var v;
    int     i;

    i = 1;
    tmp = *stack_a;
    while (tmp)
    {
        tmp->index = -1;
        tmp->check_max = -1;
        tmp->part = -1;
        tmp = (tmp)->next;
    }
    while (i <= argc)
    {
        tmp = *stack_a;
        if (i == 1)
            ft_get_min(stack_a, &v, argc);
        ft_get_min_opt(stack_a, argc, &v, i);
        while (tmp->content != v.min)
            tmp = tmp->next;
        tmp->index = i++;
    }
}

int main(int argc, char  **argv)
{
    t_list      *stack_a;
    t_list      *stack_b;

    stack_a = NULL;
    stack_b = NULL; 
    if (argc > 1)
    {    
        if (ft_parsing(argc, argv, &stack_a) == 255)
            return (255);
        argc = ft_lstsize(stack_a);
        ft_index(&stack_a, argc);
        if (argc > 1 && argc < 4)
            ft_sort_three(&stack_a, argc);
        else if (argc == 4 )
            ft_sort_four(&stack_a, &stack_b);
        else if (argc == 5)
            ft_sort_five(&stack_a, &stack_b);
        else
        {
            if (ft_check_sort(&stack_a, argc))
                return (0);
            ft_sort_big_nbr(stack_a, stack_b, argc);
        }
    }
    return (0);
}


