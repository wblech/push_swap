#include "push_swap.h"

void ft_error(t_error error)
{
    if (error == enotdigit || error == eduplicated || error == emaxint)
        ft_putstr_fd("Error", STDERR_FILENO);
}

void *print_error_free_arr(t_error error, int *arr)
{
    ft_error(error);
    if(arr != NULL)
        free(arr);
    return(NULL);
}