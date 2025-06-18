# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmamzer <rmamzer@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/03 16:44:05 by rmamzer           #+#    #+#              #
#    Updated: 2025/06/18 17:20:10 by rmamzer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

CC = cc

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

HEADERS = push_swap.h

SRCS = check_functions.c free_and_exit.c node_utils.c push_operations.c \
		push_swap.c reverse_rotate_operations.c rotate_operations.c \
		sort_big_node_info.c sort_big_node_move.c swap_operations.c

OBJS = $(SRCS:.c=.o)
.SECONDARY: ${OBJS}

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT) ${HEADERS}
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME) $(LIBFT)

re: fclean all

.PHONY: all re clean fclean
