/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 00:19:27 by relamine          #+#    #+#             */
/*   Updated: 2024/03/09 09:41:57 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.c"

int main(int argc, char  **argv)
{
    int parsing;

    parsing = ft_parsing(argc, argv);
    if (parsing == 255)
        return (255);
    else if (parsing == -1)
        return (0);
    
    return (0);
}