CC=gcc
CFLAGS=-Wall -Wextra -Werror
SRCS = main.c calculation.c valid.c
OBJS = main.o calculation.o valid.o
NAME=do-op

all: $(NAME)

$(NAME) : $(SRCS)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

clean: 
	rm -f $(OBJS)
 
fclean: clean
	rm -f $(NAME)

re : fclean all