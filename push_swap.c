/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 00:19:27 by relamine          #+#    #+#             */
/*   Updated: 2024/03/10 11:54:59 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.c"

int main(int argc, char  **argv)
{
    int parsing;
    char    *head;

    head = NULL;
    parsing = ft_parsing(argc, argv, &head);
    if (parsing == 255)
        return (255);
    else if (parsing == -1)
        return (0);
    
    return (0);
}