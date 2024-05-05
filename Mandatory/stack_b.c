/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:45:07 by relamine          #+#    #+#             */
/*   Updated: 2024/04/29 18:28:24 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_organize_b(t_var_a *vp, int a, int b)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = (*vp->node_a);
	vp->argc = ft_lstsize(*vp->node_a);
	while (++i <= vp->argc)
	{
		if (ft_lstsize(*vp->node_b) == b)
			return ;
		if (tmp->index <= b)
		{
			pb(vp->node_a, vp->node_b);
			if ((*vp->node_b)->index > (a + ((b - a) / 2)))
				rb(vp->node_b);
		}
		else
			ra(vp->node_a);
		tmp = (*vp->node_a);
	}
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
	a = (argc) / chunks;
	i = 1;
	j = 1;
	while (j < chunks)
	{
		ft_organize_b(&vp, i, a * j);
		i += a;
		j++;
	}
	if (argc > 100)
	{
		ft_organize_b(&vp, i, argc - 5);
		ft_sort_five(stack_a, stack_b);
	}
	else
		ft_organize_b(&vp, i, argc);
}

void	ft_index(t_list **stack, int argc)
{
	t_list	*tmp;
	t_var	v;
	int		i;

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
