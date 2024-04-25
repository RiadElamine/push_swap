/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:02:23 by relamine          #+#    #+#             */
/*   Updated: 2024/04/24 08:32:08 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
