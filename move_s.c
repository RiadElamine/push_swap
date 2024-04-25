/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:57:57 by relamine          #+#    #+#             */
/*   Updated: 2024/04/19 12:13:29 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort(t_list *lst, char *msg)
{
	int	value;

	if (!lst || lst->next == NULL)
		return ;
	value = lst->content;
	lst->content = lst->next->content;
	lst->next->content = value;
	write(1, msg, 3);
}

void	sa(t_list *lst)
{
	sort(lst, "sa\n");
}

void	sb(t_list *lst)
{
	sort(lst, "sb\n");
}

void	ss(t_list *lst_a, t_list *lst_b)
{
	sort(lst_a, NULL);
	sort(lst_b, NULL);
	if (lst_a->next == NULL && lst_b->next == NULL)
		return ;
	write(1, "ss\n", 3);
}
