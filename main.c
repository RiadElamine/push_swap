/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 00:19:27 by relamine          #+#    #+#             */
/*   Updated: 2024/04/24 10:00:40 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1)
		return (1);
	if (ft_parsing(argc, argv, &stack_a) == 255)
		return (255);
	argc = ft_lstsize(stack_a);
	ft_index(&stack_a, argc);
	if (argc > 1 && argc < 4)
		ft_sort_three(&stack_a, argc);
	else if (argc == 4)
		ft_sort_four(&stack_a, &stack_b);
	else if (argc == 5)
		ft_sort_five(&stack_a, &stack_b);
	else if (argc > 5)
	{
		if (ft_check_sort(&stack_a, argc))
			return (0);
		ft_sort_big_ls(&stack_a, stack_b, argc);
	}
	ft_lstclear(stack_a);
}
