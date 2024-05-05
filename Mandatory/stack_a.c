/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:38:29 by relamine          #+#    #+#             */
/*   Updated: 2024/04/28 15:13:21 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push_a(t_list **stack_a, t_list **stack_b, int a, int value)
{
	int		argc;
	t_list	*tmp;

	argc = 1;
	tmp = *stack_b;
	while (tmp && tmp->index != value)
	{
		argc++;
		tmp = tmp->next;
	}
	if (argc <= (ft_lstsize(*stack_b) / 2))
		while (a--)
			rb(stack_b);
	else
		while (a--)
			rrb(stack_b);
	pa(stack_a, stack_b);
}

static int	ft_postition(t_list *stack_b, int value)
{
	int	i;
	int	size;

	i = 0;
	size = ft_lstsize(stack_b);
	while (stack_b)
	{
		if (stack_b->index == value)
		{
			if (i >= (size / 2))
				return (size - i);
			return (i);
		}
		i++;
		stack_b = stack_b->next;
	}
	return (i);
}

void	ft_push_to_a(t_list **stack_a, t_list **stack_b)
{
	int	ismax;
	int	imax;
	int	max;
	int	before_max;

	while (*stack_b)
	{
		max = ft_lstsize(*stack_b);
		before_max = max - 1;
		ismax = ft_postition(*stack_b, before_max);
		imax = ft_postition(*stack_b, max);
		if (ismax < imax)
		{
			ft_push_a(stack_a, stack_b, ismax, before_max);
			imax = ft_postition(*stack_b, max);
			ft_push_a(stack_a, stack_b, imax, max);
			sa(*stack_a);
		}
		else
			ft_push_a(stack_a, stack_b, imax, max);
	}
}
