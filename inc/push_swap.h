#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdbool.h>
# include "libft.h"
# include "error.h"

# ifndef NULL
#  define NULL ((void *)0)
# endif

void ft_error(t_error error);
void bubble_sort(int *arr, int size);

#endif