#include "push_swap.h"

static int	binary_search(int *arr, int left, int right, int search_nbr)
{
	int	mid;

	if (right >= left)
	{
		mid = left + (right - left) / 2;
		if (arr[mid] == search_nbr)
			return (mid);
		if (arr[mid] > search_nbr)
			return (binary_search(arr, left, mid - 1, search_nbr));
		return (binary_search(arr, mid + 1, right, search_nbr));
	}
	return (-1);
}

static void	simplify_nbr(t_stack *a_stack, int *sorted)
{
	unsigned int	stack_position;
	int				search_nbr;
	int				new_nbr;
	int				i;

	i = 0;
	stack_position = (unsigned int)(a_stack->top + i);
	while (stack_position < a_stack->size)
	{
		search_nbr = a_stack->arr[stack_position];
		new_nbr = binary_search(sorted, 0, a_stack->size - 1, search_nbr);
		a_stack->arr[stack_position] = new_nbr;
		i++;
		stack_position = a_stack->top + i;
	}
}

static int	bits_length(int biggest_nbr)
{
	unsigned int	max_bits;

	max_bits = 0;
	while (biggest_nbr >> max_bits)
		max_bits++;
	return (max_bits);
}

static void	radix_sort(t_holder *holder)
{
	unsigned int	j;
	unsigned int	i;
	int				biggest_nbr;
	unsigned int	max_bits;

	j = holder->a_stack->top;
	i = 0;
	biggest_nbr = holder->a_stack->size - 1;
	max_bits = bits_length(biggest_nbr);
	while (i < max_bits && !is_sorted(holder->a_stack->arr,
			holder->a_stack->size, holder->a_stack->top))
	{
		while (j < holder->a_stack->size)
		{
			if (((holder->a_stack->arr[holder->a_stack->top] >> i) & 1) == 0)
				push(holder->b_stack, holder->a_stack);
			else
				rotate(holder->a_stack, false);
			j++;
		}
		while (holder->b_stack->top != -1)
			push(holder->a_stack, holder->b_stack);
		j = holder->a_stack->top;
		i++;
	}
}

void	big_sort(t_holder *holder)
{
	simplify_nbr(holder->a_stack, holder->sorted);
	radix_sort(holder);
}
