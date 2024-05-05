/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils6_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:34:46 by relamine          #+#    #+#             */
/*   Updated: 2024/05/04 01:03:00 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

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

static int	ft_isempty(char *str)
{
	while (*str == ' ')
		str++;
	if (*str == '\0')
		return (1);
	return (0);
}

static char	**ft_oned_array(int argc, char **argv)
{
	int		j;
	char	*list;
	char	**tod_array;

	j = 1;
	list = NULL;
	while (j < argc)
	{
		if (ft_isempty(argv[j]))
		{
			if (list)
				free(list);
			return (NULL);
		}
		list = ft_strjoin(list, argv[j]);
		if (!list)
			return (NULL);
		list = ft_strjoin(list, " ");
		if (!list)
			return (NULL);
		j++;
	}
	tod_array = ft_split(list);
	return (free(list), tod_array);
}

int	ft_parsing(int argc, char **argv, t_list **head)
{
	int	err;
	int	i;

	i = 0;
	argv = ft_oned_array(argc, argv);
	if (!argv)
		return (write(2, "Error\n", 6), 255);
	err = ft_err_conv_lst(argv, head);
	while (argv[i])
		free(argv[i++]);
	if (err == 255)
		return (write(2, "Error\n", 6), free(argv), err);
	return (free(argv), 0);
}
