/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:33:58 by relamine          #+#    #+#             */
/*   Updated: 2024/05/04 01:16:14 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct node
{
	int			index;
	int			check_max;
	int			content;
	struct node	*next;
}				t_list;

typedef struct variables
{
	int			i;
	int			imin;
	int			min;
	t_list		*tmp_max;
	t_list		*tp;
	t_list		*tmp;
}				t_var;

typedef struct variable_a
{
	int			argc;
	t_list		**node_a;
	t_list		**node_b;
}				t_var_a;

int				ft_parsing(int argc, char **argv, t_list **head);
size_t			ft_strlen(char *str);
char			*ft_strdup(char *str);
char			*ft_strjoin(char *arr, char *arr2);
char			**ft_split(char *s1);
int				ft_atoi(char *str, int *is_error);
void			ft_lstadd_front(t_list **lst, t_list *newlist);
void			ft_lstclear(t_list *lst);
t_list			*ft_lstnew(int content);
void			ft_lstadd_back(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
int				ft_err_conv_lst(char **twod_array, t_list **head);
int				ft_check_sort(t_list **list, int size);
void			sa(t_list *lst);
void			sb(t_list *lst);
void			ss(t_list *lst_a, t_list *lst_b);
void			ra(t_list **lst);
void			rb(t_list **lst);
void			rr(t_list **lst_a, t_list **lst_b);
void			rra(t_list **lst);
void			rrb(t_list **lst);
void			rrr(t_list **lst_a, t_list **lst_b);
void			pb(t_list **lsta, t_list **lstb);
void			pa(t_list **lsta, t_list **lstb);
void			ft_get_min(t_list **lsta, t_var *v, int size_list);
void			ft_get_min_opt(t_list **lsta, int size_list, t_var *v, int j);
void			ft_sort_three(t_list **list, int size_list);
void			ft_sort_four(t_list **lsta, t_list **lstb);
void			ft_sort_five(t_list **lsta, t_list **lstb);
void			ft_sort_big_ls(t_list **stack_a, t_list **stack_b, int argc);
void			ft_push_to_a(t_list **stack_a, t_list **stack_b);
void			ft_push_to_b(t_list **stack_a, t_list **stack_b, int argc,
					int chunks);
void			ft_index(t_list **stack, int argc);
#endif