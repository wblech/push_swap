#include "push_swap.h"

bool validate_is_digit(int argc, char const *argv[])
{
    int i;
    int count_sign;
    bool is_digit;
    int j;

    i = 1;
    is_digit = true;
    while(i < argc && is_digit)
    {
        count_sign = 0;
        j = 0;

        while(argv[i][j] != '\0' && is_digit)
        {
            if (argv[i][j] == '-' && count_sign < 1)
                count_sign++;
            else if (!ft_isdigit(argv[i][j]))
                is_digit = false;
            j++;
        }
        j = 0;     
        i++;
    }
    return (is_digit);
}

int *convert_to_vint(int argc, char const *argv[])
{
    int i;
    int *ret_arr;

    i = 1;
    ret_arr = (int *)malloc(sizeof(int) * argc);
    while(i < argc)
    {
        ret_arr[i - 1] = ft_atoi(argv[i]);
        i++;
    }
    return ret_arr;
}
bool  is_sorted(int *arr, int size)
{
    int i;
    int last_pos;
    bool is_sorted;

    i = 0;
    last_pos = size - 1;
    is_sorted = true;
    while(i < last_pos && is_sorted)
    {
        if (arr[i] > arr[i + 1])
            is_sorted = false;
        i++;
    }
    return is_sorted;
}

bool is_duplicated(int *arr, int size)
{
    int *sorted;
    int i;
    bool is_duplicated;

    is_duplicated = false;
    sorted = (int *)malloc(sizeof(int) * size);
    i = 0;
    while(i < size)
    {
        sorted[i] = arr[i];
        i++;
    }
    bubble_sort(sorted, size);
    i = 0;
    while (i < size && !is_duplicated)
    {
        if ((sorted[i] - sorted[i + 1]) == 0)
            is_duplicated = true;
        i++;
    }
    free(sorted);
    return is_duplicated;
}

// todo precisa refatorar código duplicado
// precisa arrumar norminette
// precisa arrumar tamanho do argc 
// precisa organizar código
int *validate_argv(int argc, char const *argv[])
{
    t_error error;
    int *int_arr;

    error = no_error;
    int_arr = NULL;
    if (!validate_is_digit(argc, argv))
        ft_error(error = enotdigit);
    if (!error)
        int_arr = convert_to_vint(argc, argv);
    if (error || !int_arr || is_sorted(int_arr, argc))
    {
        ft_error(esorted);
        free(int_arr);
        int_arr = NULL;
    }
    else if (is_duplicated(int_arr, argc - 1))
    {
        ft_error(eduplicated);
        free(int_arr);
        int_arr = NULL;
    }
    return int_arr;
}

int main(int argc, char const *argv[])
{
    int *arr;
    int i;
    
    i = 0;
    if (argc < 2)
        return(0);
    arr = validate_argv(argc, argv);
    if (!arr)
        return(1);
    while(i < argc - 1)
        ft_putnbr_fd(arr[i++], STDOUT_FILENO);
}
