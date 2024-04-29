/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:50:38 by relamine          #+#    #+#             */
/*   Updated: 2024/04/29 12:50:56 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isalready_exist(t_list *list, int content)
{
	while (list)
	{
		if (list->content == content)
			return (1);
		list = list->next;
	}
	return (0);
}

static void	ft_lstmap_atoi(t_list **lst, char *str, int *is_error)
{
	t_list	*newlist;

	newlist = ft_lstnew(ft_atoi(str, is_error));
	if (!newlist)
		return (*is_error = 255, ft_lstclear(*lst));
	if (*is_error == 255 || ft_isalready_exist(*lst, newlist->content))
		return (*is_error = 255, free(newlist), ft_lstclear(*lst));
	ft_lstadd_back(lst, newlist);
}

static int	ft_opt_isdigit(char **twod_array, int i, int j)
{
	char	c;
	char	n;

	c = twod_array[i][j];
	n = twod_array[i][j + 1];
	if ((c == '-' || c == '+') && !(n >= '0' && n <= '9'))
		return (255);
	if ((c >= '0' && c <= '9') && (n == '-' || n == '+'))
		return (255);
	if (!((c >= '0' && c <= '9') || (c == '-' || c == '+')))
		return (255);
	return (0);
}

int	ft_err_conv_lst(char **twod_array, t_list **head)
{
	int	i;
	int	j;
	int	is_error;

	i = 0;
	is_error = 0;
	while (twod_array[i])
	{
		j = 0;
		while (twod_array[i][j])
		{
			if (ft_opt_isdigit(twod_array, i, j) == 255)
				return (ft_lstclear(*head), 255);
			j++;
		}
		ft_lstmap_atoi(head, twod_array[i++], &is_error);
		if (is_error == 255)
			return (is_error);
	}
	return (0);
}
