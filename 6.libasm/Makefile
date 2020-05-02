NAME = libasm.a
SRCS_PATH = ./srcs/

SRCS_FILES =	ft_strlen.s \
		ft_strcpy.s \
		ft_strcmp.s \
		ft_write.s \
		ft_read.s \
		ft_strdup.s
 
OBJS = $(SRCS_FILES:.s=.o)

%.o: %.s libasm.h
		nasm -f elf64 $<

$(NAME): $(OBJS) 
		@ar rcs $(NAME) $(OBJS)
		@ranlib $(NAME)
  
all: $(NAME)

clean:
		rm -f $(OBJS)

test:
		@gcc -Wall -Werror -Wextra -no-pie main.c libasm.a

fclean: clean
		rm -f $(NAME)
		rm -f ./a.out

re: fclean all
