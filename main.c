/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 00:19:27 by relamine          #+#    #+#             */
/*   Updated: 2024/03/29 21:44:27 by relamine         ###   ########.fr       */
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
        return (pa(lsta, lstb));
    else if ((*lstb)->content > (*lsta)->next->next->content)
        return (pa(lsta, lstb), ra(lsta), (void)0);
    else if ((*lstb)->content < (*lsta)->next->content)
        return (pa(lsta, lstb), sa(*lsta), (void)0);
    else 
        return(rra(lsta), pa(lsta, lstb), ra(lsta), ra(lsta), (void)0);
}
static var *ft_get_min_max(t_list **lsta)
{
    var *v;

    v = malloc(sizeof(var));
    if(!v)
        return (write(2, "Error\n", 6), NULL);
    v->tmp = *lsta;
    v->imax = v->tmp->content;
    v->imin = v->imax;
    while (++v->i < 6) 
    {
        if (v->imax > v->tmp->content)
        {
            v->imax = v->tmp->content;
            v->max = v->i;
        }
        if (v->imin < v->tmp->content)
        {
            v->imin = v->tmp->content;
            v->min = v->i;
        }
        v->tmp = v->tmp->next;
    }
    return (v);
}
void ft_sort_five(t_list **lsta, t_list **lstb, int size_list)
{
    var *v;

    if (ft_check_sort(lsta, size_list))
        return;
    v = ft_get_min_max(lsta);
    if (v->min == 2 || v->max == 2)
        sa(*lsta);
    else if ((v->min == 4 || v->min == 5 || v->max == 4 || v->max == 5) && (!(v->min == 1 || v->max == 1)))
    {
        if (v->max == 5 || v->min == 5 )
            rra(lsta);
        else
        {
            rra(lsta);
            rra(lsta);
        }
    }
    pb(lsta, lstb);
    ft_sort_four(lsta, lstb, 4);
    if ((*lstb)->content > (*lsta)->content)
        return (pa(lsta, lstb), ra(lsta), (void)0);
    return (pa(lsta, lstb), (void)0);
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
            return (255);
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

        
        // while (stack_a)
        // {
        //     printf("\n%d\n", (stack_a)->content);
        //     stack_a = (stack_a)->next;
        // }

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