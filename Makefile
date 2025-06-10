# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmamzer <rmamzer@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/03 16:44:05 by rmamzer           #+#    #+#              #
#    Updated: 2025/06/10 14:44:04 by rmamzer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

## UPDATE flags
CFLAGS = -g -Wall -Wextra -Werror

CC = cc

SRCS = *.c

OBJS = $(SRCS:.c=.o)
.SECONDARY: ${OBJS}

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a


all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME) $(LIBFT)

re: fclean all

## CLEAN BEFORE SUBMISSION
.PHONY: all re clean fclean test gdbtest  valgrindtest
