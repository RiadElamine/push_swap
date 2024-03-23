/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 00:19:27 by relamine          #+#    #+#             */
/*   Updated: 2024/03/23 01:10:06 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void f()
{
    system("leaks push_swap");
}
int main(int argc, char  **argv)
{
    t_list    *stack_a;
    // t_list *tmp;
    t_list    *stack_b;

    stack_a = NULL;
    stack_b = NULL; 
    
    if (argc > 1)
   {    
        if (ft_parsing(argc, argv, &stack_a) == 255)
            return (atexit(f), 255);
        if (ft_parsing(argc, argv, &stack_b) == 255)
            return (atexit(f), 255);
        //ss(stack_a, stack_b);
        // tmp = stack_a;
        // rb(&stack_b);
        // rb(&stack_b);
        puts("-------------");
        pb(&stack_a, &stack_b);
        
        while (stack_a)
        {
            printf("\n%d\n", (stack_a)->content);
            stack_a = (stack_a)->next;
        }

        puts("stack b");
    
        while (stack_b)
        {
            printf("\n%d\n", (stack_b)->content);
            stack_b = (stack_b)->next;
        }
        // rb(&stack_b);
        // ft_lstclear(tmp);
        // atexit(f);

    }
    return (0);
}