DIR_OBJ = .objs
DIR_SRC = src
DIR_INC = ./inc
DIR_LIBFT = ./libft
DIR_PRINTF = ./ft_printf
SRCS = 	$(DIR_SRC)/bubble_sort.c \
		$(DIR_SRC)/main.c \
		$(DIR_SRC)/ft_error.c \
		$(DIR_SRC)/ft_validation.c \
		$(DIR_SRC)/ft_stack_utils.c \
		$(DIR_SRC)/op_swap.c \
		$(DIR_SRC)/op_push.c \
		$(DIR_SRC)/op_rotate.c \
		$(DIR_SRC)/op_reverse_rotate.c \
		$(DIR_SRC)/tester.c #precisa remover
		

NAME = push_swap
OBJ = $(patsubst $(DIR_SRC)/%.c, $(DIR_OBJ)/%.o, $(SRCS))
CC = clang
CFLAGS = -Wall -Werror -Wextra
LFLAGS =	-L ./$(DIR_LIBFT) -L./$(DIR_PRINTF) -lft -lftprintf
AR = ar -rc
RM = rm -f
LIBFT = $(DIR_LIBFT)/libft.a
PRINTF = $(DIR_PRINTF)/libftprintf.a


$(NAME):	$(LIBFT) $(PRINTF) $(OBJ) 
			$(CC) $(CFLAGS) $(OBJ) -I./libft -I./ft_printf -I$(DIR_INC) $(LFLAGS) -g -fsanitize=address -o $@

$(DIR_OBJ)/%.o:	$(DIR_SRC)/%.c
				mkdir -p $(DIR_OBJ)
				$(CC) $(CFLAGS) -c $< -I$(DIR_LIBFT) -I$(DIR_PRINTF) -I$(DIR_INC) -g -o $@

$(LIBFT):
			$(MAKE) -C $(DIR_LIBFT)

$(PRINTF):
			$(MAKE) -C $(DIR_PRINTF)

all:	$(NAME)

clean:
	$(MAKE) -C $(DIR_LIBFT) clean
	$(RM) $(OBJ)


fclean:	clean
		$(MAKE) -C $(DIR_LIBFT) fclean
		$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re