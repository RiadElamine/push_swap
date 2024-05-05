/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 00:43:00 by relamine          #+#    #+#             */
/*   Updated: 2024/04/28 09:27:53 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_list **src, t_list **dest, char *msg)
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
	write(1, msg, 3);
}

void	pb(t_list **lsta, t_list **lstb)
{
	push(lsta, lstb, "pb\n");
}

void	pa(t_list **lsta, t_list **lstb)
{
	push(lstb, lsta, "pa\n");
}
