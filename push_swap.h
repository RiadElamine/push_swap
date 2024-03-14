/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:33:58 by relamine          #+#    #+#             */
/*   Updated: 2024/03/14 16:43:14 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# include <unistd.h>

typedef struct node
{
    int          content;
    struct node *next;
} t_list;

int ft_parsing(int argc, char **argv , t_list **head);
size_t  ft_strlen(char  *str);
char    *ft_strdup(char *str);
char    *ft_strjoin(char *arr, char *arr2);
char **ft_split(char *s1);
int ft_atoi(char    *str, int    *is_error);
int ft_isempty(char *str);
char**    ft_oned_array(int argc, char **argv);
int  ft_opt_isdigit(char c);
void ft_lstadd_front(t_list **lst, t_list *newlist);
void ft_lstclear(t_list *lst);
t_list   *ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
int  ft_isalready_exist(t_list   *list, int  content);
void ft_lstmap_atoi(t_list **lst, char  *str,  int *is_error);
int ft_err_conv_lst(char **twod_array, t_list **head);
void ft_lstmap_atoi(t_list **lst, char  *str,  int *is_error);
int ft_err_conv_lst(char **twod_array, t_list **head);
void    sa(t_list *lst);
void    sb(t_list *lst);
void ss(t_list *lst_a, t_list *lst_b);
#endif