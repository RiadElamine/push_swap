# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: relamine <relamine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/14 15:59:36 by relamine          #+#    #+#              #
#    Updated: 2024/04/29 18:26:19 by relamine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap
BONUS = checker

SOURCES =  parsing.c  utils.c  utils1.c    utils2.c    utils3.c move_s.c move_r.c move_rr.c send.c\
			stack_a.c stack_b.c get_min.c sorting_func.c
			
SRC_MAIN =  main.c

BONUS_FILES = bonus/checker_bonus.c bonus/get_next_line/get_next_line_utils.c bonus/get_next_line/get_next_line.c bonus/checker_utils_bonus.c bonus/checker_utils2_bonus.c

BONUS_OBJECTS = $(BONUS_FILES:.c=.o)
SRC_OBJECTS = $(SOURCES:.c=.o)
SRC_MAIN_OBJ = $(SRC_MAIN:.c=.o)

OBJECTS = $(SRC_OBJECTS) $(BONUS_OBJECTS)

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM =rm -f

all: $(NAME)

bonus : $(BONUS)

$(NAME): $(SRC_OBJECTS) $(SRC_MAIN_OBJ)
	$(CC) $(CFLAGS) $(SRC_MAIN_OBJ) $(SRC_OBJECTS) -o $(NAME) 

$(BONUS): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(BONUS)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(SRC_OBJECTS) $(SRC_MAIN_OBJ) $(OBJECTS)

fclean: clean
	$(RM) $(NAME) $(BONUS)

re: fclean all bonus

