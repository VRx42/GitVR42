CC = gcc

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

LIBFT = libft

DIR_S = sources

DIR_O = temporary

HEADER = include

SOURCES =master.c \
		lst_initialization.c \
		format_analysis.c \
		put_convert_buffer.c \
		conv_char.c \
		conv_int.c \
		conv_string.c \
		utils.c \
		fonctions_nulles.c \

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p temporary
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<
	@echo "Compilation de la fonction "$<

norme:
	@echo "======= CHECKING NORME ======="
	norminette ./libft/
	@echo
	norminette ./$(HEADER)/
	@echo
	norminette ./$(DIR_S)/
	@echo "======= CHECK DONE ======="

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)
	@echo "Suppresion des objets"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)
	@echo "Suppresion de la library "$(NAME)

re: fclean all

