/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:17:45 by relamine          #+#    #+#             */
/*   Updated: 2024/05/04 01:43:30 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*ft_strjoin2(char const *s1, char const *s2);
int		ft_strchr(char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup2(const char *s1);
size_t	ft_strlen2(const char *s);

#endif
