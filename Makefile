NAME = push_swap
SOURCES =  parsing.c   main.c utils.c     utils1.c    utils2.c    utils3.c\

    

OBJECTS = $(SOURCES:.c=.o)
#B_OBJECTS = $(BSOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM =rm -f


all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) 

#bonus: $(B_OBJECTS)
#	$(AR) $(NAME) $(B_OBJECTS)
%.o : %.c 
	$(CC) $(CFLAGS) -c $< 
clean:
	$(RM) $(OBJECTS) $(B_OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all