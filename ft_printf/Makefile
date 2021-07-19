DIR_OBJ = .objs
DIR_SRC = src
DIR_LIBFT = ../libft
SRCS =  $(DIR_SRC)/ft_adt.c \
				$(DIR_SRC)/ft_getinfo.c \
				$(DIR_SRC)/ft_getvalue.c \
				$(DIR_SRC)/ft_helpers.c \
				$(DIR_SRC)/ft_helpers_second.c \
				$(DIR_SRC)/ft_precision.c \
				$(DIR_SRC)/ft_printf.c \
				$(DIR_SRC)/ft_width.c \
				$(DIR_SRC)/ft_zeroflag.c \
				$(DIR_SRC)/ft_uitoa_base.c
NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJ = $(patsubst $(DIR_SRC)/%.c, $(DIR_OBJ)/%.o, $(SRCS))
AR = ar -rc
RM = rm -f
LIBFT = $(DIR_LIBFT)/libft.a

all:	$(NAME)

$(DIR_OBJ)/%.o:	$(DIR_SRC)/%.c
				mkdir -p $(DIR_OBJ)
				$(CC) $(CFLAGS) -I. -I$(DIR_LIBFT) -c $< -o $@

$(NAME): $(OBJ)
				$(AR) $(NAME) $(OBJ)
				ranlib $(NAME)

clean:
			$(RM) $(OBJ)

fclean: clean
			$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
