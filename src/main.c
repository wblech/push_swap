#include "push_swap.h"

void sort(t_holder *holder)
{
    if(holder->a_stack->size <= 5)
        small_sort(holder);
    // else
    //     big_sort(a_stack, b_stack);
}

int main(int argc, char const *argv[])
{
    int i;
    t_holder *holder;
    
    i = 0;
    if (argc < 2)
        return(0);

    holder = get_valid_holder(argc, argv);
    if(holder != NULL)
    {
        sort(holder);
        while((unsigned int)i < holder->a_stack->size)
        {
            if(holder->a_stack->top == -1 || holder->a_stack->top > i)
                ft_printf("%-5c", ' ');
            else if (holder->a_stack->top <= i)
                ft_printf("%-5i", holder->a_stack->arr[i]);
            if(holder->b_stack->top == -1 || holder->b_stack->top > i)
                ft_printf("\n");
            else if (holder->b_stack->top <= i)
                ft_printf("%i\n", holder->b_stack->arr[i]);
            i++;
        }
        ft_printf("%c%5c\n", holder->a_stack->name, holder->b_stack->name);
    }

    //teste
        // tester(holder);
    //fim teste
    // free_holder(holder);
}
