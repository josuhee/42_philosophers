CC=gcc
SRCS=src/main.c src/philo.c src/time.c\
		src/action.c src/init.c src/message.c\
		src/monitor.c src/free.c
OBJS=$(SRCS:.c=.o)
NAME=philo
HEADER=-I include/
CFLAG=-pthread -fsanitize=address

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
