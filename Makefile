DIR_OBJ = .objs
DIR_SRC = src
DIR_INC = ./inc
DIR_LIBFT = ./libft
SRCS = 	$(DIR_SRC)/bubble_sort.c \
		$(DIR_SRC)/main.c \
		$(DIR_SRC)/ft_error.c
		

NAME = push_swap
OBJ = $(patsubst $(DIR_SRC)/%.c, $(DIR_OBJ)/%.o, $(SRCS))
CC = clang
CFLAGS = -Wall -Werror -Wextra
LFLAGS =	-L ./$(DIR_LIBFT) -lft
AR = ar -rc
RM = rm -f
LIBFT = $(DIR_LIBFT)/libft.a


$(NAME):	$(LIBFT) $(OBJ) 
			$(CC) $(CFLAGS) $(OBJ) -I./libft -I$(DIR_INC) $(LFLAGS) -g -o $@

$(DIR_OBJ)/%.o:	$(DIR_SRC)/%.c
				mkdir -p $(DIR_OBJ)
				$(CC) $(CFLAGS) -c $< -I$(DIR_LIBFT) -I$(DIR_INC) -g -o $@

$(LIBFT):
			$(MAKE) -C $(DIR_LIBFT)

all:	$(NAME)

clean:
	$(MAKE) -C $(DIR_LIBFT) clean
	$(RM) $(OBJ)


fclean:	clean
		$(MAKE) -C $(DIR_LIBFT) fclean
		$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re