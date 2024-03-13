/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:55:44 by relamine          #+#    #+#             */
/*   Updated: 2024/03/13 18:07:53 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char **ft_split(char *s1)
{
    char    **s2;
    size_t  rows;
    
    rows = ft_row_size(s1);
    s2 = malloc((rows + 1)* sizeof(char *));
    if (!s2)
        return (NULL);
    return (ft_strsplit(rows, s2, s1), s2);
}
 char**    ft_oned_array(int argc, char **argv)
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
    return (ft_split(list));
}
 int  ft_opt_isdigit(char c)
{
    return ((c == '-' || c == '+') || (c >= '0' && c <= '9'));
}
 int ft_atoi(char    *str, int    *is_error)
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
            return (*is_error = 255, 255);
        else if (signe == 1 && (res > (214748364) || ((res == (214748364) && *str > '7'))))
            return (*is_error = 255, 255);
        res = res * 10 + (*(str++) - '0');
    }
    return (res * signe);
}


t_list   *ft_lstnew(int content)
{
    t_list *newlist;

    newlist = malloc(sizeof(t_list));
    if(!newlist)
        return (write(2, "Error\n", 6), NULL);
    newlist->content = content;
    newlist->next = NULL;
    return (newlist);
}
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!*lst)
	{
		(*lst) = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}