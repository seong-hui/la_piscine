CC=gcc
CFLAGS=-Wall -Wextra -Werror
INC = includes
AR=ar -rc
SRCS =  ./srcs/ft_putchar.c ./srcs/ft_swap.c ./srcs/ft_putstr.c ./srcs/ft_strlen.c ./srcs/ft_strcmp.c
OBJS=${SRCS:.c=.o}
TARGET=libft.a

all: $(TARGET)

$(TARGET) : $(OBJS)
	$(AR) $(TARGET) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -I $(INC) -o $@ -c $<

clean: 
	rm -f $(OBJS)
 
fclean: clean
	rm -f $(TARGET)

re : fclean all