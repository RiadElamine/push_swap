/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:33:58 by relamine          #+#    #+#             */
/*   Updated: 2024/03/13 18:09:43 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stdio.h>
# include <stdlib.h>
#include <string.h>
# include <unistd.h>

typedef struct node
{
    int          content;
    struct node *next;
} t_list;

int ft_parsing(int argc, char **argv , t_list **head);
void ft_lstmap_atoi(t_list **lst, char  *str,  int *is_error);
int ft_err_conv_lst(char **twod_array, t_list **head);
void ft_lstadd_front(t_list **lst, t_list *newlist);
void ft_lstclear(t_list *lst);
int  ft_isalready_exist(t_list   *list, int  content);
void ft_lstmap_atoi(t_list **lst, char  *str,  int *is_error);
int ft_err_conv_lst(char **twod_array, t_list **head);
char **ft_split(char *s1);
char**    ft_oned_array(int argc, char **argv);
int  ft_opt_isdigit(char c);
int ft_atoi(char    *str, int    *is_error);
t_list   *ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
size_t  ft_column_size(char   *str);
char **ft_strsplit(size_t rows, char **s2, char *s1);
size_t  ft_strlen(char  *str);
char    *ft_strdup(char *str);
char    *ft_strjoin(char *arr, char *arr2);
int ft_isempty(char *str);
 size_t  ft_row_size(char   *str);


#endif