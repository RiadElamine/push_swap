# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: relamine <relamine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/14 15:59:36 by relamine          #+#    #+#              #
#    Updated: 2024/05/04 01:48:15 by relamine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker

SOURCES =  Mandatory/parsing.c Mandatory/main.c Mandatory/utils.c  Mandatory/utils1.c Mandatory/utils2.c Mandatory/utils3.c Mandatory/move_s.c Mandatory/move_r.c\
			Mandatory/move_rr.c Mandatory/send.c Mandatory/stack_a.c Mandatory/stack_b.c Mandatory/get_min.c Mandatory/sorting_func.c

BONUS_FILES = bonus/checker_bonus.c bonus/get_next_line_bonus/get_next_line_utils_bonus.c bonus/get_next_line_bonus/get_next_line_bonus.c\
				bonus/utils/checker_utils_bonus.c bonus/utils/checker_utils2_bonus.c bonus/utils/checker_utils3_bonus.c  bonus/utils/checker_utils4_bonus.c\
				bonus/utils/checker_utils5_bonus.c bonus/utils/checker_utils6_bonus.c bonus/utils/checker_utils7_bonus.c bonus/moves/move_s_bonus.c\
				bonus/moves/move_r_bonus.c bonus/moves/move_rr_bonus.c bonus/moves/send_bonus.c 

BONUS_OBJECTS = $(BONUS_FILES:.c=.o)
SRC_OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM =rm -f


bonus/%.o: bonus/%.c bonus/checker_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

Mandatory/%.o: Mandatory/%.c Mandatory/push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

bonus : $(BONUS)

$(BONUS) : $(BONUS_OBJECTS)
	$(CC) $(CFLAGS) $(BONUS_OBJECTS) -o $(BONUS)
	
$(NAME): $(SRC_OBJECTS)
	$(CC) $(CFLAGS) $(SRC_OBJECTS) -o $(NAME) 	

clean:
	$(RM) $(SRC_OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	$(RM) $(NAME) $(BONUS)

re: fclean all bonus

