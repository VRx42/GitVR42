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

SRCS = srcs/core/helloworld.c \

NAME = Cub3D
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
	@$(CC) -o $@ $^ -I srcs/core/ -L srcs/minilibx/ -lmlx -lXext -lX11
	@echo "DONE :)"
#gcc -I ../minilibx helloworld.c -L ../minilibx -lmlx -lXext -lX11


clean:
	rm -f $(OBJS)
	make -C srcs/libft/ clean
	make -C srcs/minilibx/ clean

fclean: clean
	rm -f $(NAME)
	make -C srcs/libft/ fclean
	make -C srcs/minilibx/ clean

re: fclean all

