/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:59:23 by relamine          #+#    #+#             */
/*   Updated: 2024/05/04 01:48:26 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../bonus/get_next_line_bonus/get_next_line_bonus.h"
# include <fcntl.h>

typedef struct node
{
	int			index;
	int			check_max;
	int			content;
	struct node	*next;
}				t_list;

typedef struct buffer
{
	char			*moves;
	struct buffer	*next;
}	t_buffer;

typedef struct variables
{
	int			i;
	int			imin;
	int			min;
	t_list		*tmp_max;
	t_list		*tp;
	t_list		*tmp;
}				t_var;

int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_check_mov(char *move, t_buffer **lst_moves);
void		ft_checker_sort(t_list **stack_a, int argc);
t_buffer	*ft_movenew(char *content);
void		ft_apply_mov(t_buffer *lst_moves, t_list **stack_a,
				t_list **stack_b);
void		ft_moveadd_back(t_buffer **lst, t_buffer *new);
void		ft_moveclear(t_buffer *lst);
char		**ft_split(char *s1);
int			ft_err_conv_lst(char **twod_array, t_list **head);
t_list		*ft_lstnew(int content);
void		ft_lstadd_front(t_list **lst, t_list *newlist);
void		ft_lstclear(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
size_t		ft_strlen(char *str);
char		*ft_strdup(char *str);
char		*ft_strjoin(char *arr, char *arr2);
int			ft_atoi(char *str, int *is_error);
int			ft_parsing(int argc, char **argv, t_list **head);
void		sa(t_list *lst);
void		sb(t_list *lst);
void		ss(t_list *lst_a, t_list *lst_b);
void		ra(t_list **lst);
void		rb(t_list **lst);
void		rr(t_list **lst_a, t_list **lst_b);
void		rra(t_list **lst);
void		rrb(t_list **lst);
void		rrr(t_list **lst_a, t_list **lst_b);
void		pb(t_list **lsta, t_list **lstb);
void		pa(t_list **lsta, t_list **lstb);
void		ft_index(t_list **stack, int argc);

#endif