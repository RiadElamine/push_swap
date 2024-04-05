/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 00:19:27 by relamine          #+#    #+#             */
/*   Updated: 2024/04/05 18:12:08 by relamine         ###   ########.fr       */
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
    if (!v)
        v = ft_get_min(lsta, size_list);
    else
    {
        v->tp = *lsta;
        while (v->tp->index != -1)
            v->tp = v->tp->next;
        v->min = v->tp->content;
    }
    v->tmp = *lsta;
    v->i = 0;
    while (++v->i < size_list + 1) 
    {
        if (v->min > v->tmp->content && v->tmp->index == -1)
            v->min = v->tmp->content;
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
static void ft_index(t_list **stack_a, int argc)
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
    v = NULL;
    i = 1;
    while (i <= argc)
    {
        tmp = *stack_a;
        v = ft_get_min_opt(stack_a, argc, v);
        while (tmp->content != v->min)
            tmp = tmp->next;
        tmp->index = i++;
    }
    return (free(v), (void)0);
}
static int ft_organize_b(t_list **stack_a, t_list **stack_b, int argc, int n, int a, int b)
{
    t_list *tmp;
    int i;
    int c;

    i = n;
    c = 0;
    while (++i <= argc)
    {
        tmp = *stack_a;
        if (tmp->index >= a && tmp->index <= b)
        {
            pb(stack_a, stack_b);
            (*stack_b)->index = tmp->index;
            if((*stack_b)->next != NULL)
            {
                if ((*stack_b)->index > (*stack_b)->next->index && n != a - 1 && c < (b - a) / 2)
                {
                    rb(stack_b);
                    c++;
                }
            }
            n++;
        }
        else
            ra(stack_a);
    }
    return (n);
}

static int ft_push_to_b(t_list **stack_a, t_list **stack_b, int argc)
{
    int a;
    int n;

    a = argc / 3;
    n = ft_organize_b(stack_a, stack_b, argc, 0, 1, a);
    n = ft_organize_b(stack_a, stack_b, argc, n, a + 1, a * 2);
    if ((a * 3) != argc)
        n = ft_organize_b(stack_a, stack_b, argc, n, (a * 2) + 1, (a * 3));
    else
        n = ft_organize_b(stack_a, stack_b, argc, n, (a * 2) + 1, argc - 1);
    return (n);
}
int ft_organize_a(t_list **stack_a, t_list **stack_b, int argc, int n, int a, int b)
{
    t_list *tmp;
    int max;
    int i;

    i = n;
    while (++i <= argc)
    {
        tmp = *stack_a;
        max = tmp->index;
        if (tmp->index >= a && tmp->index <= b && tmp->index > max)
            max = tmp->index;
    }
    while (++i <= argc)
    {
        tmp = *stack_a;
        if (tmp->index >= a && tmp->index <= b && tmp->index == max)
            pa(stack_a, stack_b);
        else
            rb(stack_b);
    }
    return (n);
}
void ft_push_to_a(t_list **stack_a, t_list **stack_b, int argc)
{
    int a;
    int n;

    a = argc / 3;
    n = ft_organize_a(stack_a, stack_b, argc, 0, 1, a);
    // n = ft_organize_a(stack_a, stack_b, argc, n, a + 1, a * 2);
    // ft_organize_a(stack_a, stack_b, argc, n, (a * 2) + 1, argc);
}
int main(int argc, char  **argv)
{
    t_list      *stack_a;
    t_list      *stack_b;
    t_list      *tmp;

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
            tmp = stack_a;
            while (tmp->next)
            {
                printf("%d---> %d \n", tmp->index, tmp->content);
                tmp =tmp->next;
            }
            printf("%d---> %d \n", tmp->index, tmp->content);
            puts("--------------");
            ft_push_to_b(&stack_a, &stack_b, argc);
            // ft_push_to_a(&stack_a, &stack_b, ft_push_to_b(&stack_a, &stack_b, argc));

            tmp = stack_a;
            // while (tmp->next)
            // {
            //     printf("%d---> %d \n", tmp->index, tmp->content);
            //     tmp =tmp->next;
            // }
            // printf("%d---> %d \n", tmp->index, tmp->content);
            
            
            // puts("--------------");

            
            // while (stack_b->next)
            // {
            //     printf("b-----%d---> %d \n", stack_b->index, stack_b->content);
            //     stack_b =stack_b->next;
            // }
            // printf("b-----%d---> %d \n", stack_b->index, stack_b->content);
        }
    }
    return (0);
}
