/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_s_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:57:57 by relamine          #+#    #+#             */
/*   Updated: 2024/05/04 01:17:06 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

static void	sort(t_list *lst)
{
	int	value;

	if (!(lst) || !(lst)->next)
		return ;
	value = lst->content;
	lst->content = lst->next->content;
	lst->next->content = value;
}

void	sa(t_list *lst)
{
	sort(lst);
}

void	sb(t_list *lst)
{
	sort(lst);
}

void	ss(t_list *lst_a, t_list *lst_b)
{
	sort(lst_a);
	sort(lst_b);
}
