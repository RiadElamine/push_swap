/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils7_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 01:10:52 by relamine          #+#    #+#             */
/*   Updated: 2024/05/04 01:15:31 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

void	ft_get_min(t_list **lsta, t_var *v, int size_list)
{
	int	i;

	v->tmp = *lsta;
	v->min = v->tmp->content;
	i = 0;
	while (++i < size_list + 1)
	{
		if (v->min >= v->tmp->content)
		{
			v->min = v->tmp->content;
			v->imin = i;
		}
		v->tmp = v->tmp->next;
	}
}

void	ft_get_min_opt(t_list **lsta, int size_list, t_var *v, int j)
{
	int	i;

	if (j != 1)
	{
		v->tp = *lsta;
		while (v->tp->index != -1)
			v->tp = v->tp->next;
		v->min = v->tp->content;
	}
	v->tmp = *lsta;
	i = 0;
	while (++i < size_list + 1)
	{
		if (v->min > v->tmp->content && v->tmp->index == -1)
			v->min = v->tmp->content;
		v->tmp = v->tmp->next;
	}
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
