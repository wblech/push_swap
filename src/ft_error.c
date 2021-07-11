#include "push_swap.h"

void ft_error(t_error error)
{
    if (error == enotdigit || error == eduplicated || error == emaxint)
        ft_putstr_fd("Error", STDERR_FILENO);
}