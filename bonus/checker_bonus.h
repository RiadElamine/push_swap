/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:59:23 by relamine          #+#    #+#             */
/*   Updated: 2024/04/29 13:26:42 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../bonus/get_next_line/get_next_line.h"
# include "../push_swap.h"
# include <fcntl.h>

typedef struct buffer
{
	char			*moves;
	struct buffer	*next;
}	t_buffer;

int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_check_mov(char *move, t_buffer **lst_moves);
void		ft_checker_sort(t_list **stack_a, int argc, int new_stdout);
t_buffer	*ft_movenew(char *content);
void		ft_apply_mov(t_buffer *lst_moves, t_list **stack_a,
				t_list **stack_b);
void		ft_moveadd_back(t_buffer **lst, t_buffer *new);
void		ft_moveclear(t_buffer *lst);

#endif