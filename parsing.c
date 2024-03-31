/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 00:26:12 by relamine          #+#    #+#             */
/*   Updated: 2024/03/29 22:36:54 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_parsing(int argc, char **argv , t_list **head)
{
    int     err;
    int     i;

    i = 0;
    argv = ft_oned_array(argc, argv);
    if (!argv)
        return (write(2, "Error\n", 6), 255);
    err = ft_err_conv_lst(argv, head);
    if (err == 255)
    {
        while (argv[i])
            free(argv[i++]);
        return (write(2, "Error\n", 6), free(argv), err);
    }
    return (free(argv), 0);
}
