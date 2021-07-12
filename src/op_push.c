#include "push_swap.h"

static void pop(t_stack *stack)
{
    stack->top += 1;
    if (stack->top == (int)stack->size)
        stack->top = -1;
}

void push(t_stack *stack_add, t_stack *stack_removed)
{
    unsigned int new_top;

    if (stack_add->top == -1)
        new_top = stack_add->size - 1;
    else
        new_top = stack_add->top - 1;
    if (stack_removed->top == -1)
        return ;
    stack_add->arr[new_top] = stack_removed->arr[stack_removed->top];
    stack_add->top = new_top;
    pop(stack_removed);
    ft_printf("p%c\n", stack_add->name);
}