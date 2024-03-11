/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 00:26:12 by relamine          #+#    #+#             */
/*   Updated: 2024/03/11 11:32:21 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
# include <stdlib.h>
#include <string.h>
# include <unistd.h>
#include <libc.h>



typedef struct node
{
    int          content;
    struct node *next;
} t_list;



static size_t  ft_strlen(char  *str)
{
    size_t  i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

static char    *ft_strdup(char *str)
{
    char    *tb;
    int     i;
    int     j;

    tb = malloc(ft_strlen(str) + 1);
    if (!tb)
        return (NULL);
    i = 0;
    j = 0;
    while (str[j])
        tb[i++] = str[j++];
    return (tb[i] = '\0', tb);
}

static char    *ft_strjoin(char *arr, char *arr2)
{
    char    *tb;
    int     i;
    int     j;

    if (!arr)
        return (ft_strdup(arr2));
    tb = malloc(ft_strlen(arr)+ ft_strlen(arr2) + 1);
    if(!tb)
        return (free(arr), NULL);
    i = 0;
    j = 0;
    while (arr[i])
        tb[i++] = arr[j++];
    j = 0;
    while (arr2[j])
        tb[i++] = arr2[j++];
    return (free(arr), tb[i] = '\0', tb);
}
static int ft_isempty(char *str)
{
    while (*str == ' ')
    {
        if (*str == '\0')
            return (1);
        str++;
    }
    return (0);
}
static char*    ft_oned_array(int argc, char **argv)
{
    int     j;
    char    *list;

    j = 1;
    list = NULL;
    while (j < argc)
    {
        if (ft_isempty(argv[j]))
            return (NULL);
        list = ft_strjoin(list, argv[j]);
        if (!list)
            return (NULL);
        list = ft_strjoin(list, " ");
        if (!list)
            return (NULL);
        j++;
    }
    return (list);
}
static size_t  ft_row_size(char   *str)
{
    size_t  row_len;

    row_len = 0;
    while (*str)
    {
        while (*str == ' ')
            str++;
        if(!*str)
            break;
        while (*str != ' ')
            str++;
        row_len++;
    }
    return (row_len);
}
static size_t  ft_column_size(char   *str)
{
    size_t  column_len;

    column_len = 0;
    while (str[column_len] && str[column_len] != ' ')
        column_len++;
    return (column_len);
}
static char **ft_strsplit(size_t rows, char **s2, char *s1)
{
    size_t  j;
    size_t  columns;
    size_t  i;

    i = 0;
    while (i < rows)
    {
        while (*s1 == ' ')
            s1++;
        columns = ft_column_size(s1);
        s2[i] = malloc(columns + 1);
        if (!s2[i])
        {
            while (i >= 0)
                free(s2[--i]);
            return (free(s2), NULL);
        }
        j = 0;
        while (j < columns)
            s2[i][j++] = *(s1++);
        s2[i][j] = '\0';
        i++;
    }
    return(s2[i] = NULL, s2);
}
static char **ft_split(char *s1)
{
    char    **s2;
    size_t  rows;
    
    rows = ft_row_size(s1);
    s2 = malloc((rows + 1)* sizeof(char *));
    if (!s2)
        return (NULL);
    return (ft_strsplit(rows, s2, s1), s2);
}
static int  ft_opt_isdigit(char c)
{
    return ((c == '-' || c == '+') || (c >= '0' && c <= '9'));
}
static int ft_atoi(char    *str, int    *is_error)
{
    int     signe;
    long    res;

    signe = 1;
    res = 0;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            signe = -1;
        str++;
    }
    while (*str)
    {
        if (signe == -1 && ((res > (214748364)) || ((res == (214748364)) && *str > '8')))
            return (write(2, "Error\n", 6), *is_error = 255, 255);
        else if (signe == 1 && (res > (214748364) || ((res == (214748364) && *str > '7'))))
            return (write(2, "Error\n", 6), *is_error = 255, 255);
        res = res * 10 + (*(str++) - '0');
    }
    return (res * signe);
}
static int ft_err_conv_lst(char **twod_array, t_list **head)
{
    int    i;
    int     j;
    int     is_error;

    i = 0;
    is_error = 0;
    while (twod_array[i])
    {
        j = 0;
        while (twod_array[i][j])
        {
            if (!ft_opt_isdigit(twod_array[i][j]))
                return(write(2, "Error\n", 6), 255);
            if (twod_array[i][j + 1] == '+' || twod_array[i][j + 1] == '-')
                return(write(2, "Error\n", 6), 255);
            j++;
        }
        ft_lstmap_atoi(head, twod_array[i], &is_error);
        if (is_error == 255)
            return (write(2, "Error\n", 6), is_error);
        i++;
    }
    return (0);
}

//############################################################

static t_list   *ft_lstnew(int content)
{
    t_list *newlist;

    newlist = malloc(sizeof(t_list));
    if(!newlist)
        return (write(2, "Error\n", 6), NULL);
    newlist->content = content;
    newlist->next = NULL;
    return (newlist);
}
static t_list   *ft_lastlst(t_list *lst)
{
    t_list *last_list;

    last_list = NULL;
    while (lst)
    {
        last_list = lst;
        lst = lst->next;
    }
    return (last_list);
}
static void ft_lstadd_back(t_list **lst, t_list *newlist)
{
    if (!lst)
        return ;
    if (!*lst && newlist)
        (*lst)->next = newlist;
    else
    {
        *lst = ft_lastlst(*lst);
        (*lst)->next = newlist;    
    }
}
static void ft_lstadd_front(t_list **lst, t_list *newlist)
{
    if (!lst || !newlist)
        return;
    newlist->next = *lst;
    *lst = newlist;
}
static void ft_lstclear(t_list *lst)
{
    t_list *nexlist;

    if (!lst)
		return ;
    while (lst)
    {
        nexlist = lst->next;
        free(lst);
        lst = nexlist;
    }     
}
static int  ft_isalready_exist()
{
    
}
static void ft_lstmap_atoi(t_list **lst, char  *str,  int *is_error)
{
    t_list  *newlist;

    if (!*lst)
    {
        newlist = ft_lstnew(NULL);
        if (!newlist)
            return (*is_error = 255);
        newlist->content = ft_atoi(str, is_error);
        if (*is_error == 255)
            return (free(newlist), *is_error = 255);
        *lst = newlist;
    }
    newlist = ft_lstnew(NULL);
    if (!newlist)
        return (ft_lstclear(*lst), *is_error = 255);
    newlist->content = ft_atoi(str, is_error);
    if (*is_error == 255)
        return (free(newlist), ft_lstclear(*lst), *is_error = 255);
    if (ft_isalready_exist(lst, newlist->content))
        return (free(newlist), ft_lstclear(*lst), *is_error = 255);
    ft_lstadd_back(lst, newlist);
}


int ft_parsing(int argc, char **argv, t_list **head)
{
    char    *list;
    char    **twod_array;
    int     err;

    if (argc <= 1)
        return (-1);
    list = ft_oned_array(argc, argv);
    if (!list)
        return (write(2, "Error\n", 6), 255);
    twod_array = ft_split(list);
    if (!twod_array)
        return (write(2, "Error\n", 6), 255);
    err = ft_err_conv_lst(twod_array, head);
    if (err == 255)
        return (err);
    return (0);
}



//check in map if there are two content same
