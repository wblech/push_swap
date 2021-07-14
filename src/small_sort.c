#include "push_swap.h"

void sort_2(t_stack *a_stack)
{
    swap(a_stack, false);
}

void sort_3(t_stack *a_stack)
{
    int *arr;

    arr = a_stack->arr;
    if(arr[a_stack->top + 2] > arr[a_stack->top] && arr[a_stack->top] > arr[a_stack->top + 1])
        swap(a_stack, false);
    else if(arr[a_stack->top] > arr[a_stack->top + 1] && arr[a_stack->top + 1] > arr[a_stack->top + 2])
    {
        swap(a_stack, false);
        reverse_rotate(a_stack, false);
    }
    else if(arr[a_stack->top] > arr[a_stack->top + 2] && arr[a_stack->top + 2] > arr[a_stack->top + 1])
        rotate(a_stack, false);
    else if(arr[a_stack->top + 1] > arr[a_stack->top + 2] && arr[a_stack->top + 2] > arr[a_stack->top])
    {
        swap(a_stack, false);
        rotate(a_stack, false);
    }
    else
        reverse_rotate(a_stack, false);
}

void sort_4(t_holder *holder)
{
    t_stack *a_stack;
    t_stack *b_stack;
    int first_nbr;

    first_nbr = holder->sorted[0];
    a_stack = holder->a_stack;
    b_stack = holder->b_stack;
    while(a_stack->arr[a_stack->top] != first_nbr)
        rotate(a_stack, false);
    push(b_stack, a_stack);
    sort_3(a_stack);
    push(a_stack, b_stack);    
}

void sort_5(t_holder *holder)
{
    t_stack *a_stack;
    t_stack *b_stack;
    int middle;
    int middle_index;

    middle_index = 2;
    middle = holder->sorted[middle_index];
    a_stack = holder->a_stack;
    b_stack = holder->b_stack;
    while(a_stack->top != middle_index)
    {
        if(a_stack->arr[a_stack->top] < middle)
            push(b_stack, a_stack);
        else
            rotate(a_stack, false);
    }      
    sort_3(a_stack);
    if(b_stack->arr[b_stack->top] < b_stack->arr[b_stack->top + 1])
        sort_2(b_stack);
    push(a_stack, b_stack);    
    push(a_stack, b_stack);    
}

void small_sort(t_holder *holder)
{
    if(holder->a_stack->size < 3)
        sort_2(holder->a_stack);
    else if(holder->a_stack->size < 4)
        sort_3(holder->a_stack);
    else if(holder->a_stack->size < 5)
        sort_4(holder);
    else
        sort_5(holder);
}