# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vronchin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/22 15:55:48 by vronchin          #+#    #+#              #
#    Updated: 2019/11/25 14:46:00 by vronchin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
LIBH	=	libft.h
CC 		=	gcc
FILES	=	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c \
ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
ft_memmove.c ft_memset.c ft_putchar_fd.c \
ft_putendl_fd.c ft_putnbr_fd.c \
ft_putstr_fd.c ft_strchr.c \
ft_strdup.c\
ft_strjoin.c ft_strlcat.c ft_strlen.c\
ft_strmapi.c ft_strncmp.c ft_strncpy.c  \
ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_tolower.c\
ft_toupper.c ft_substr.c ft_strlcpy.c ft_calloc.c ft_split.c\

SOURCES_BONUS = ft_lstnew.c ft_lstadd_front.c\
				ft_lstsize.c ft_lstlast.c\
				ft_lstadd_back.c ft_lstiter.c\
				ft_lstdelone.c ft_lstclear.c\
				ft_lstmap.c

OBJECT_BONUS = $(SOURCES_BONUS:.c=.o)

CFLAG	=	-Wall -Wextra -Werror
OBJ		=	$(FILES:.c=.o)

all		:	$(NAME) bonus
$(NAME)	:	$(OBJ) $(LIBH)
			$(CC) $(CFLAG) -c $(FILES) -I $(LIBH)
			ar rc $(NAME) $(OBJ)
clean	:
			rm -f $(OBJ) $(OBJECT_BONUS)
fclean: clean
			rm -f $(NAME)
re: fclean all

bonus	:
			gcc $(CFLAG) -c $(SOURCES_BONUS) $(FILES) $(LIBH)
			ar rc $(NAME) $(OBJ) $(OBJECT_BONUS)
			ranlib $(NAME)
