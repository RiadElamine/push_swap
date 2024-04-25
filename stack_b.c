/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:45:07 by relamine          #+#    #+#             */
/*   Updated: 2024/04/25 03:48:44 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_organize_b(t_var_a *vp, int a, int b)
{
	int		i;
	int		c;
	t_list	*tmp;

	i = 0;
	c = 0;
	tmp = (*vp->node_a);
	while (++i <= vp->argc)
	{
		if (tmp->index >= a && tmp->index <= b)
		{
			pb(vp->node_a, vp->node_b);
			if ((*vp->node_b)->index > (a + ((b - a) / 2)))
				rb(vp->node_b);
			c++;
		}
		else
			ra(vp->node_a);
		tmp = (*vp->node_a);
	}
	vp->argc = vp->argc - c;
}

void	ft_push_to_b(t_list **stack_a, t_list **stack_b, int argc, int chunks)
{
	int		a;
	t_var_a	vp;
	int		i;
	int		j;

	vp.node_a = stack_a;
	vp.node_b = stack_b;
	vp.argc = argc;

	i = ft_lstsize(*stack_a) / chunks;
	j = 0;
	a = i;
	t_list **tmp = stack_a;
	while(*tmp)
	{
		if((*tmp)->index <= a)
		{
			pb(stack_a,stack_b);
			j++;
			if((*stack_b)->index < (a - (i /2)))
				rb(stack_b);	
			if(j == a)
				a += i;
		}
		else
			ra(stack_a);
	}
	
	// tmp = *stack_b;
	// while(tmp)
	// {
	// 	printf("content of ===%d \n",tmp->content);
	// 	tmp = tmp->next;
	// }
	
	// a = (argc) / chunks;
	// i = 1;
	// j = 1;
	
	// while (j < chunks)
	// {
	// 	ft_organize_b(&vp, i, a * j);
	// 	if(i == j)
	// 		i += a;
	// 	j++;
	// }
	// ft_organize_b(&vp, i, argc -5 );
}

void	ft_index(t_list **stack, int argc)
{
	t_list		*tmp;
	t_var		v;
	int			i;

	i = 1;
	tmp = *stack;
	while (tmp)
	{
		tmp->index = -1;
		tmp->check_max = -1;
		tmp = (tmp)->next;
	}
	while (i <= argc)
	{
		tmp = *stack;
		if (i == 1)
			ft_get_min(stack, &v, argc);
		ft_get_min_opt(stack, argc, &v, i);
		while (tmp->content != v.min)
			tmp = tmp->next;
		tmp->index = i++;
	}
}
