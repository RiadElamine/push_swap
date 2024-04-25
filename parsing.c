/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 00:26:12 by relamine          #+#    #+#             */
/*   Updated: 2024/04/19 12:14:00 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
