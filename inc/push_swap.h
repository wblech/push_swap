#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <stdarg.h>
# include <stdbool.h>
# include "error.h"
# include "libft.h"

typedef struct s_stack
{
	int				*arr;
	char			name;
	int				top;
	unsigned int	size;
}	t_stack;

typedef struct s_holder
{
	int			*sorted;
	t_stack		*a_stack;
	t_stack		*b_stack;
}	t_holder;

typedef enum e_name
{
	a = 97,
	b = 98
}	t_name;

/*
* ft_error.c
*/
void		ft_error(t_error error);
void		*print_error_free_arr(t_error error, int *arr);

/*
* ft_bubble_sort.c
*/
void		bubble_sort(int *arr, int size);

/*
* ft_validation.c
*/
int			*get_valid_int_arr(int size, char const *argv[], int *sorted);

/*
* ft_validation_utils.c
*/
bool		is_sorted(int *arr, int size, int top);
bool		is_valid_int(long long int nbr);

/*
* ft_stack_utils.c
*/
t_stack		*create_stack(unsigned int size, int *arr, t_name name);
t_holder	*get_valid_holder(int argc, char const *argv[]);
void		free_stack(t_stack *stack);
void		free_holder(t_holder *holder);

/*
* op_swap.c
*/
void		swap(t_stack *stack, bool is_ss);
void		ss(t_holder *holder);

/*
* op_push.c
*/
void		push(t_stack *stack_add, t_stack *stack_removed);

/*
* op_rotate.c
*/
void		rotate(t_stack *stack, bool is_rr);
void		rr(t_holder *holder);

/*
* op_reverse_rotate.c
*/
void		reverse_rotate(t_stack *stack, bool is_rrr);
void		rrr(t_holder *holder);

/*
* small_sort.c
*/
void		sort_2(t_stack *a_stack);
void		sort_3(t_stack *a_stack);
void		sort_4(t_holder *holder);
void		sort_5(t_holder *holder);
void		small_sort(t_holder *holder);

/*
* big_sort.c
*/
void		big_sort(t_holder *holder);

#endif
