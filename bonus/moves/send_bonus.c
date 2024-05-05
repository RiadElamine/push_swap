/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 00:43:00 by relamine          #+#    #+#             */
/*   Updated: 2024/05/04 00:19:34 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

static void	push(t_list **src, t_list **dest)
{
	t_list	*send;
	t_list	*next_send;

	if (!*src)
		return ;
	send = (*src);
	next_send = (*dest);
	(*src) = (*src)->next;
	(*dest) = send;
	send->next = next_send;
}

void	pb(t_list **lsta, t_list **lstb)
{
	push(lsta, lstb);
}

void	pa(t_list **lsta, t_list **lstb)
{
	push(lstb, lsta);
}
