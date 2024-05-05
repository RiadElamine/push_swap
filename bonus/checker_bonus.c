/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:58:22 by relamine          #+#    #+#             */
/*   Updated: 2024/05/04 01:22:10 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	ft_next(t_list **stack_a, t_list **stack_b, t_buffer *lst_moves)
{
	ft_apply_mov(lst_moves, stack_a, stack_b);
	ft_moveclear(lst_moves);
}

int	main(int argc, char **argv)
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_buffer	*lst_moves;
	char		*input;

	stack_a = NULL;
	stack_b = NULL;
	lst_moves = NULL;
	if (argc <= 1)
		return (1);
	if (ft_parsing(argc, argv, &stack_a) == 255)
		return (255);
	argc = ft_lstsize(stack_a);
	input = get_next_line(0);
	while (input != NULL)
	{
		if (ft_check_mov(input, &lst_moves))
			return (free(input), ft_moveclear(lst_moves), ft_lstclear(stack_b),
				ft_lstclear(stack_a), write(2, "Error\n", 6), 1);
		free(input);
		input = get_next_line(0);
	}
	ft_next(&stack_a, &stack_b, lst_moves);
	ft_checker_sort(&stack_a, argc);
	return (ft_lstclear(stack_a), ft_lstclear(stack_b), 0);
}
