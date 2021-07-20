#include "push_swap.h"

void	rotate(t_stack *stack, bool is_rr)
{
	int	tmp;
	int	i;
	int	last_index;

	last_index = stack->size - 1;
	if (stack->top == -1 || stack->top == last_index)
		return ;
	i = stack->top;
	tmp = stack->arr[stack->top];
	while (i < last_index)
	{
		stack->arr[i] = stack->arr[i + 1];
		i++;
	}
	stack->arr[last_index] = tmp;
	if (!is_rr)
	{
		ft_putstr_fd("r", STDOUT_FILENO);
		ft_putchar_fd(stack->name, STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
}

void	rr(t_holder *holder)
{
	bool	is_rr;

	is_rr = true;
	rotate(holder->a_stack, is_rr);
	rotate(holder->b_stack, is_rr);
	ft_putstr_fd("rr\n", STDOUT_FILENO);
}
