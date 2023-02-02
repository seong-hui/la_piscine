CC=gcc
CFLAGS=-Wall -Wextra -Werror
SRCS = ft_atoi.c ft_split.c ft_strdup.c main.c ft_solve.c ft_make_info.c ft_extra.c
OBJS=${SRCS:.c=.o}
NAME=bsq

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean: 
	rm -f $(OBJS)
 
fclean: clean
	rm -f $(NAME)

re : fclean all