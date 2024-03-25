/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 00:19:27 by relamine          #+#    #+#             */
/*   Updated: 2024/03/25 09:48:02 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void f()
{
    system("leaks push_swap");
}
static int ft_check_sort(t_list **list, int size)
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
void ft_sort_four(t_list **lsta, t_list **lstb, int size_list)
{
    if (ft_check_sort(lsta, size_list))
        return;
    pb(lsta, lstb);
    ft_sort_three(lsta, 3); 
    if ((*lstb)->content < (*lsta)->content)
        return;
    else if ((*lstb)->content > (*lsta)->next->next->content)
        return (pa(lsta, lstb), ra(lsta), (void)0);
    else if ((*lstb)->content < (*lsta)->next->content)
        return (pa(lsta, lstb), sa(*lsta), (void)0);
    else
        return(rra(lsta), pa(lsta, lstb), ra(lsta), ra(lsta), (void)0);
}
void ft_sort_five(t_list **lsta, t_list **lstb, int size_list)
{
    t_list *tmp;
    int i;

    if (ft_check_sort(lsta, 5))
        return;
    tmp = *lsta;
    i = 0;
    while (i < size_list && ((*lsta)->next->next->content >= tmp->content)) 
    {
        tmp = tmp->next;
        i++;
    }
    if (i == 5)
    {
        pb(lsta, lstb);
        pb(lsta, lstb);
        if ((*lstb)->content < (*lsta)->next->content && (*lstb)->next->content < (*lsta)->next->content)
        {
            if ((*lstb)->content < (*lstb)->next->content)
                sb(*lstb);
            return(ft_sort_three(lsta, 3), pa(lsta, lstb), pa(lsta, lstb), (void)0);
        }
        else
        {
            if ((*lstb)->content > (*lstb)->next->content)
                return(ft_sort_three(lsta, 3), rrr(lsta, lstb), pa(lsta, lstb), ra(lsta), pa(lsta, lstb), ra(lsta), ra(lsta),(void)0);
            return(ft_sort_three(lsta, 3), rra(lsta), pa(lsta, lstb), ra(lsta), pa(lsta, lstb), ra(lsta), ra(lsta),(void)0);
        }
    }
    // else
    // {
        
    // }
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
        // if (ft_parsing(argc, argv, &stack_b) == 255)
        //     return (atexit(f), 255);
       
        argc = ft_lstsize(stack_a);
        if (argc > 1 && argc < 4)
            ft_sort_three(&stack_a, argc);
        if (argc == 4 )
            ft_sort_four(&stack_a, &stack_b, argc);
        if (argc == 5)
            ft_sort_five(&stack_a, &stack_b, argc);

        // puts("-------------");
        // pb(&stack_a,&stack_b);
        // pb(&stack_a,&stack_b);
        // ra(&stack_a);
        // rra(&stack_a);
        // pa(&stack_a,&stack_b);
        // ra(&stack_a);
        // pa(&stack_a,&stack_b);
        // ra(&stack_a);
        // ra(&stack_a);

        
        while (stack_a)
        {
            printf("\n%d\n", (stack_a)->content);
            stack_a = (stack_a)->next;
        }

        // puts("stack b");
    
        // rb(&stack_b);
        // while (stack_b)
        // {
        //     printf("\n%d\n", (stack_b)->content);
        //     stack_b = (stack_b)->next;
        // }
        // ft_lstclear(tmp);
        // atexit(f);

    }
    return (0);
}
