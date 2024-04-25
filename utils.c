/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:34:46 by relamine          #+#    #+#             */
/*   Updated: 2024/04/19 12:41:38 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*tb;
	int		i;
	int		j;

	tb = malloc(ft_strlen(str) + 1);
	if (!tb)
		return (NULL);
	i = 0;
	j = 0;
	while (str[j])
		tb[i++] = str[j++];
	return (tb[i] = '\0', tb);
}

char	*ft_strjoin(char *arr, char *arr2)
{
	char	*tb;
	int		i;
	int		j;

	if (!arr)
		return (ft_strdup(arr2));
	tb = malloc(ft_strlen(arr) + ft_strlen(arr2) + 1);
	if (!tb)
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

int	ft_atoi(char *str, int *is_error)
{
	int		signe;
	long	res;

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
		if (signe == -1 && ((res > (214748364)) || ((res == (214748364))
					&& *str > '8')))
			return (*is_error = 255, 255);
		else if (signe == 1 && (res > (214748364) || ((res == (214748364)
						&& *str > '7'))))
			return (*is_error = 255, 255);
		res = res * 10 + (*(str++) - '0');
	}
	return (res * signe);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ls;

	if (!lst)
		return (NULL);
	while (lst)
	{
		ls = lst;
		lst = lst->next;
	}
	return (ls);
}
