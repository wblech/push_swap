#include "push_swap.h"

void reverse_rotate(t_stack *stack, bool is_rrr)
{
    int tmp;
    int i;
    int last_index;

    last_index = stack->size - 1;
    if (stack->top == -1 || stack->top == last_index)
        return ;
    i = last_index;
    tmp = stack->arr[last_index];
    while (i > stack->top)
    {
        stack->arr[i] = stack->arr[i - 1];
        i--;
    }
    stack->arr[stack->top] = tmp;
    if(!is_rrr)
        ft_printf("rr%c\n", stack->name);
}

void rrr(t_holder *holder)
{
    bool is_rrr;

    is_rrr = true;
    reverse_rotate(holder->a_stack, is_rrr);
    reverse_rotate(holder->b_stack, is_rrr);
    ft_printf("rrr\n");
}