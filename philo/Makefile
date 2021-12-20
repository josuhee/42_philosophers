CC=gcc
SRCS=src/main.c src/philo.c src/time.c
OBJS=$(SRCS:.c=.o)
NAME=philo
HEADER=-I include/
CFLAG=

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAG) -o $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAG) -c -o $@ $< $(HEADER)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
