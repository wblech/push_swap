#include "push_swap.h"

t_stack *create_stack(unsigned int size, int *arr, t_name name)
{
    t_stack *stack;

    stack = (t_stack *)malloc(sizeof(t_stack) * 1);
    if(name == a)
        stack->top = 0;
    else
        stack->top = -1;
    stack->arr = arr;
    stack->size = size;
    stack->name = name;
    return(stack);
}

t_holder *create_holder(int size, int *int_arr, int *sorted)
{
    t_holder *holder;
    int *b_buffer;

    b_buffer = (int *)malloc(sizeof(int) * size);
    holder = (t_holder *)malloc(sizeof(t_holder) * 1);
    if (!holder)
        return holder;
    holder->sorted = sorted;
    holder->a_stack = create_stack(size, int_arr, a);
    holder->b_stack = create_stack(size, b_buffer, b);
    return holder;
}

t_holder *get_valid_holder(int argc, char const *argv[])
{
    int *int_arr;
    int *sorted;
    int size;
    t_holder *holder;

    int_arr = NULL;
    size = argc - 1;
    sorted = (int *)malloc(sizeof(int) * size);
    int_arr = get_valid_int_arr(size, argv, sorted);
    if(!int_arr)
    {
        holder = NULL;
        free(sorted);
        sorted = NULL;
    }
    else
        holder = create_holder(size, int_arr, sorted);
    if(!holder)
    {
        free(int_arr);
        if(sorted != NULL)
            free(sorted);
    }
    return holder;
}

void free_stack(t_stack *stack)
{
    if(stack != NULL)
    {
        if (stack->arr != NULL)
            free(stack->arr);
        free(stack);
    }
}

void free_holder(t_holder *holder)
{
    free_stack(holder->a_stack);
    free_stack(holder->b_stack);
    free(holder->sorted);
    free(holder);
}