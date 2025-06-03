# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmamzer <rmamzer@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/03 16:44:05 by rmamzer           #+#    #+#              #
#    Updated: 2025/06/03 16:44:17 by rmamzer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

CC = cc

SRCS = *.c

OBJS = $(SRCS:.c=.o)
.SECONDARY: ${OBJS}

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

## Different tests --> DELETE BEFORE SUBMISSION
test: 
	@cc $(SRCS) main.c
	@./a.out
	@rm -f a.out

gdbtest: 
	cc $(SRCS) -g main.c

valgrindtest:
	@cc $(SRCS) -g main.c
	@valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./a.out
	@rm -f ./a.out 
	

## CLEAN BEFORE SUBMISSION
.PHONY: all re clean fclean test gdbtest  valgrindtest 