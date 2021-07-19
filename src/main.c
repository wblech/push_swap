#include "push_swap.h"

int binary_search(int *arr, int left, int right, int search_nbr)
{
    int mid;

    if(right >= left)
    {
        mid = left + (right - left) / 2;
        if(arr[mid] == search_nbr)
            return(mid);
        if(arr[mid] > search_nbr)
            return(binary_search(arr, left, mid - 1, search_nbr));
        return(binary_search(arr, mid + 1, right, search_nbr));
    }
    return(-1);
}

void big_sort(t_holder *holder)
{
    unsigned int i;
    int search_nbr;
    int new_nbr;
    unsigned int stack_position;
    int biggest_nbr;
    unsigned int max_bits;

    i = 0;
    stack_position = (unsigned int)(holder->a_stack->top + i);
    biggest_nbr = holder->a_stack->size - 1;
    max_bits = 0;
    while(stack_position < holder->a_stack->size)
    {
        search_nbr =  holder->a_stack->arr[stack_position];
        new_nbr = binary_search(holder->sorted, 0, holder->a_stack->size - 1, search_nbr); //se voltar -1 deu erro
        holder->a_stack->arr[stack_position] = new_nbr;
        i++;
        stack_position = holder->a_stack->top + i;
    }
    while(biggest_nbr >> max_bits)
        max_bits++;
    i = 0;
    unsigned int j;
    j = holder->a_stack->top;
    while(i < max_bits && !is_sorted(holder->a_stack->arr, holder->a_stack->size, holder->a_stack->top))
    {
        while(j < holder->a_stack->size) 
        {
            if(((holder->a_stack->arr[holder->a_stack->top] >> i) & 1) == 0)
                push(holder->b_stack, holder->a_stack);
            else
                rotate(holder->a_stack, false);
            j++;
        }
        while(holder->b_stack->top != -1)
            push(holder->a_stack, holder->b_stack);
        j = holder->a_stack->top;
        i++;
    }
    // ft_putnbr_fd(max_bits, STDOUT_FILENO);

    // i = 0;
    // stack_position = (unsigned int)(holder->a_stack->top + i);
    // while(stack_position < holder->a_stack->size)
    // {
    //     ft_putnbr_fd(holder->a_stack->arr[i++], STDOUT_FILENO);
    //     ft_putstr_fd("\n", STDOUT_FILENO);
    //     stack_position = holder->a_stack->top + i;
    // }
    
}

void sort(t_holder *holder)
{
    if(holder->a_stack->size <= 5)
        small_sort(holder);
    else
        big_sort(holder);
}

int main(int argc, char const *argv[])
// int main(void)
{

    (void)argc;

    // int max_num = ft_atoi(argv[1]); // the biggest number in a is stack_size - 1
    // int max_bits = 0; // how many bits for max_num 

    // while ((max_num >> max_bits) != 0) ++max_bits;


    // ft_putnbr_fd(max_bits, STDOUT_FILENO);

    t_holder *holder;
    holder = get_valid_holder(argc, argv);

    int i;
    
    i = 0;
    if (argc < 2)
        return(0);

    if(holder != NULL)
    {
        // sort(holder);
        sort(holder);
        // while((unsigned int)i < holder->a_stack->size)
        // {
        //     if(holder->a_stack->top == -1 || holder->a_stack->top > i)
        //         ft_printf("%-5c", ' ');
        //     else if (holder->a_stack->top <= i)
        //         ft_printf("%-5i", holder->a_stack->arr[i]);
        //     if(holder->b_stack->top == -1 || holder->b_stack->top > i)
        //         ft_printf("\n");
        //     else if (holder->b_stack->top <= i)
        //         ft_printf("%i\n", holder->b_stack->arr[i]);
        //     i++;
        // }
        // ft_printf("%c%5c\n", holder->a_stack->name, holder->b_stack->name);
    }

    //teste
        // tester(holder);
    //fim teste
    // free_holder(holder);
}
