/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:02:09 by relamine          #+#    #+#             */
/*   Updated: 2024/04/28 12:18:20 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*st1;
	unsigned char	*st2;

	st1 = (unsigned char *)s1;
	st2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (st1[i] != '\0' && st2[i] != '\0' && i < (n - 1) && st1[i] == st2[i])
		i++;
	return (st1[i] - st2[i]);
}

t_buffer	*ft_movenew(char *content)
{
	t_buffer	*newlist;

	newlist = malloc(sizeof(t_buffer));
	if (!newlist)
		return (write(2, "Error\n", 6), NULL);
	newlist->moves = content;
	newlist->next = NULL;
	return (newlist);
}

int	ft_check_mov(char *move, t_buffer **lst_moves)
{
	if (ft_strncmp(move, "sa\n", 3) == 0)
		return (ft_moveadd_front(lst_moves, ft_movenew("sa")), 0);
	else if (ft_strncmp(move, "sb\n", 3) == 0)
		return (ft_moveadd_front(lst_moves, ft_movenew("sb")), 0);
	else if (ft_strncmp(move, "ss\n", 3) == 0)
		return (ft_moveadd_front(lst_moves, ft_movenew("ss")), 0);
	else if (ft_strncmp(move, "rra\n", 4) == 0)
		return (ft_moveadd_front(lst_moves, ft_movenew("rra")), 0);
	else if (ft_strncmp(move, "rrb\n", 4) == 0)
		return (ft_moveadd_front(lst_moves, ft_movenew("rrb")), 0);
	else if (ft_strncmp(move, "rrr\n", 4) == 0)
		return (ft_moveadd_front(lst_moves, ft_movenew("rrr")), 0);
	else if (ft_strncmp(move, "ra\n", 3) == 0)
		return (ft_moveadd_front(lst_moves, ft_movenew("ra")), 0);
	else if (ft_strncmp(move, "rb\n", 3) == 0)
		return (ft_moveadd_front(lst_moves, ft_movenew("rb")), 0);
	else if (ft_strncmp(move, "rr\n", 3) == 0)
		return (ft_moveadd_front(lst_moves, ft_movenew("rr")), 0);
	else if (ft_strncmp(move, "pa\n", 3) == 0)
		return (ft_moveadd_front(lst_moves, ft_movenew("pa")), 0);
	else if (ft_strncmp(move, "pb\n", 3) == 0)
		return (ft_moveadd_front(lst_moves, ft_movenew("pb")), 0);
	return (1);
}

void	ft_helper(char *content, t_list **stack_a, t_list **stack_b)
{
		if (ft_strncmp(content, "sa", 2) == 0)
			return (sa(*stack_a));
		else if (ft_strncmp(content, "sb", 2) == 0)
			return (sb(*stack_b));
		else if (ft_strncmp(content, "ss", 2) == 0)
			return (ss(*stack_a, *stack_b));
		else if (ft_strncmp(content, "rra", 3) == 0)
			return (rra(stack_a));
		else if (ft_strncmp(content, "rrb", 3) == 0)
			return (rrb(stack_b));
		else if (ft_strncmp(content, "rrr", 3) == 0)
			return (rrr(stack_a, stack_b));
		else if (ft_strncmp(content, "ra", 2) == 0)
			return (ra(stack_a));
		else if (ft_strncmp(content, "rb", 2) == 0)
			return (rb(stack_b));
		else if (ft_strncmp(content, "rr", 2) == 0)
			return (rr(stack_a, stack_b));
		else if (ft_strncmp(content, "pa", 2) == 0)
			return (pa(stack_a, stack_b));
		else if (ft_strncmp(content, "pb", 2) == 0)
			return (pb(stack_a, stack_b));
}

void	ft_apply_mov(t_buffer *lst_moves, t_list **stack_a, t_list **stack_b)
{
	while (lst_moves)
	{
		ft_helper(lst_moves->moves, stack_a, stack_b);
		lst_moves = lst_moves->next;
	}
}
