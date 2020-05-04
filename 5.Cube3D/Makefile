# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vronchin <vronchin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/30 00:21:35 by vronchin          #+#    #+#              #
#    Updated: 2020/04/30 00:30:37 by vronchin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


PHONY: libft minilibx

SRCS = srcs/core/main.c \
	srcs/core/parser.c \
	srcs/core/parser_tex.c \

NAME = exec
GCC_FLAG = -Wall -Werror -Wextra -g
CC = gcc $(GCC_FLAG)

OBJS = $(SRCS:.c=.o)

all: libft minilibx $(NAME)

libft:
	@make -C srcs/libft/

minilibx:
	@make -C srcs/minilibx/


$(%.o): $(%.c)
	@$(CC) -o $@ -c $^

$(NAME): $(OBJS)
	@echo "===COMPILATION==="
	@$(CC) -o $(NAME) $^ -I srcs/core/ -L srcs/minilibx/ -lmlx -lXext -lX11
	@echo "DONE :)"

clean:
	rm -f $(OBJS)
	rm -f $(NAME)
#	make -C srcs/libft/ clean
#	make -C srcs/minilibx/ clean

fclean: clean
	rm -f $(NAME)
	make -C srcs/libft/ fclean
	make -C srcs/minilibx/ clean

re: clean all
#make re pour dégager seulement les .o des sources CORE sans toucher aux libft et minilibx qu'on en va pas toucher
