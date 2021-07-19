#include "push_swap.h"

void swap(t_stack *stack, bool is_ss)
{
    int temp;
    int last_index;
    int second_element_index;

    second_element_index = stack->top + 1;
    last_index = stack->size - 1;
    if(stack->size < 2 || stack->top == last_index)
        return ;
    temp = stack->arr[stack->top];
    stack->arr[stack->top] = stack->arr[second_element_index];
    stack->arr[second_element_index] = temp;
    if(!is_ss)
    {
        ft_putstr_fd("s", STDOUT_FILENO);
        ft_putchar_fd(stack->name, STDOUT_FILENO);
        ft_putstr_fd("\n", STDOUT_FILENO);
    }
        // ft_printf("ss%c \n", stack->name);
}

void ss(t_holder *holder)
{
    bool is_ss;

    is_ss = true;
    swap(holder->a_stack, is_ss);
    swap(holder->b_stack, is_ss);
    ft_printf("ss\n");
}