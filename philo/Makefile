# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sujo <sujo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 16:26:01 by sujo              #+#    #+#              #
#    Updated: 2022/01/04 16:30:09 by sujo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
SRCS=src/main.c src/philo.c src/time.c\
		src/action.c src/init.c src/message.c\
		src/monitor.c src/free.c
OBJS=$(SRCS:.c=.o)
NAME=philo
HEADER=-I include/
#CFLAG=-pthread -fsanitize=address
CFLAG=-Wall -Wextra -Werror

FG_YELLOW	=\e[33m
FG_RED		=\e[31m
FG_BLUE		=\e[34m
FG_MAGENTA	=\e[35m
FG_CYAN		=\e[36m
NO_COLOR	=\e[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAG) -o $@ $(OBJS)
	@printf "$(FG_MAGENTA)🧙🏻‍♂️ 철학자 생성 🧙🏻‍♂️$(NO_COLOR)\n"

%.o: %.c
	@$(CC) $(CFLAG) -c -o $@ $< $(HEADER)

clean:
	@rm -f $(OBJS)
	@printf "$(FG_YELLOW)👻 .o 파일들을 삭제하였습니다 👻\n$(NO_COLOR)"

fclean: clean
	@rm -f $(NAME)
	@printf "$(FG_RED)🍀 실행파일을 삭제하였습니다 🍀\n$(NO_COLOR)"

re: fclean all

.PHONY: all clean fclean re
