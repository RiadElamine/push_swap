/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 00:19:27 by relamine          #+#    #+#             */
/*   Updated: 2024/03/13 18:07:22 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char  **argv)
{
    
    t_list    *head;

    head = NULL;
    
    
    if (argc > 1)
   {    
        if (ft_parsing(argc, argv, &head) == 255)
            return (255);
        while (head)
        {
            printf("%d\n", (head)->content);
            head = (head)->next;
        }
    }
    return (0);
}