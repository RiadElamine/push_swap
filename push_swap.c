/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 00:19:27 by relamine          #+#    #+#             */
/*   Updated: 2024/03/11 09:13:26 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.c"

typedef struct node
{
    int          content;
    struct node *next;
} t_list;

int main(int argc, char  **argv)
{
    int parsing;
    t_list    *head;

    head = NULL;
    parsing = ft_parsing(argc, argv, &head);
    if (parsing == 255)
        return (255);
    else if (parsing == -1)
        return (0);
    
    return (0);
}