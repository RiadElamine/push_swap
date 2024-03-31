/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 00:19:27 by relamine          #+#    #+#             */
/*   Updated: 2024/03/31 15:21:10 by relamine         ###   ########.fr       */
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
static void ft_sort_three(t_list **list, int size_list)
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
static var *ft_get_min(t_list **lsta , int size_list)
{
    var *v;

    v = malloc(sizeof(var));
    if(!v)
        return (write(2, "Error\n", 6), NULL);
    v->tmp = *lsta;
    v->min = v->tmp->content;
    while (++v->i < size_list + 1) 
    {
        if (v->min > v->tmp->content)
        {
            v->min = v->tmp->content;
            v->imin = v->i;
        }
        v->tmp = v->tmp->next;
    }
    return (v);
}
static var *ft_get_min_opt(t_list **lsta , int size_list, var *v)
{
    v->i = 0;
    v->tmp = *lsta;
    v->tp = v->tmp;
    while (v->tp->index != -1)
    {
        v->tp = v->tp->next;
    }
    v->min = v->tp->content;
    while (++v->i < size_list + 1) 
    {
        if (v->min > v->tmp->content && v->tmp->index == -1)
        {
            v->min = v->tmp->content;
            v->imin = v->i;
        }
        v->tmp = v->tmp->next;
    }
    return (v);
}
static void ft_sort_four(t_list **lsta, t_list **lstb, int size_list)
{
    if (ft_check_sort(lsta, size_list))
        return;
        var *v;
    if (ft_check_sort(lsta, size_list))
        return;
    v = ft_get_min(lsta, size_list);
    if (v->imin == 2)
        sa(*lsta);
    if (v->imin == 3)
    {
        ra(lsta);
        ra(lsta);
    }
    else if (v->imin == 4)
        rra(lsta);
    pb(lsta, lstb);
    ft_sort_three(lsta, 3);
    return (pa(lsta, lstb), free(v),(void)0);
}
static void ft_sort_five(t_list **lsta, t_list **lstb, int size_list)
{
    var *v;

    if (ft_check_sort(lsta, size_list))
        return;
    v = ft_get_min(lsta, size_list);
    if (v->imin == 2)
        sa(*lsta);
    if (v->imin == 3)
    {
        ra(lsta);
        ra(lsta);
    }
    else if ((v->imin == 5 || v->imin == 4) && (!(v->imin == 1 || v->imin == 1)))
    {
        if (v->imin == 4 || v->imin == 4 )
            rra(lsta);
        rra(lsta);
    }
    pb(lsta, lstb);
    ft_sort_four(lsta, lstb, 4);
    return (pa(lsta, lstb), free(v), (void)0);
}  

void ft_index(t_list **stack_a, int argc)
{
    t_list *tmp;
    int     i;
    var *v;

    tmp = *stack_a;
    while (tmp)
    {
        tmp->index = -1;
        tmp = (tmp)->next;
    }
    tmp = *stack_a;
    v = ft_get_min(stack_a, argc);
    while (tmp->content != v->min)
        tmp = tmp->next;
    tmp->index = 1;
    i = 2;
    while (i <= argc)
    {
        tmp = *stack_a;
        v = ft_get_min_opt(stack_a, argc, v);
        while (tmp->content != v->min)
            tmp = tmp->next;
        tmp->index = i++;
    }
    return;
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
        if (argc > 1 && argc < 4)
            ft_sort_three(&stack_a, argc);
        else if (argc == 4 )
            ft_sort_four(&stack_a, &stack_b, argc);
        else if (argc == 5)
            ft_sort_five(&stack_a, &stack_b, argc);
        else
        {
            ft_index(&stack_a, argc);

            while (stack_a->next)
            {
                printf("%d---> %d \n", stack_a->index, stack_a->content);
                stack_a =stack_a->next;
            }
            printf("%d---> %d \n", stack_a->index, stack_a->content);
        }
    }
    return (0);
}
