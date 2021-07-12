#include "push_swap.h"

static bool validate_is_digit(int size, char const *argv[])
{
    int i;
    int count_sign;
    bool is_digit;
    int j;

    i = 1;
    is_digit = true;
    while(i < size && is_digit)
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

static int *convert_to_vint(int size, char const *argv[])
{
    int i;
    int *ret_arr;

    i = 1;
    ret_arr = (int *)malloc(sizeof(int) * size);
    while((i - 1) < size)
    {
        ret_arr[i - 1] = ft_atoi(argv[i]);
        i++;
    }
    return ret_arr;
}

static bool  is_sorted(int *arr, int size)
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

static bool is_duplicated(int *arr, int size)
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

int *get_valid_int_arr(int size, char const *argv[])
{
    t_error error;
    int *int_arr;
 
    error = no_error;
    int_arr = NULL;
    if (!validate_is_digit(size, argv))
        ft_error(error = enotdigit);
    if (!error)
        int_arr = convert_to_vint(size, argv);
    if (error || !int_arr || is_sorted(int_arr, size))
        int_arr = print_error_free_arr(esorted, int_arr);
    else if (is_duplicated(int_arr, size))
        int_arr = print_error_free_arr(eduplicated, int_arr);
    return int_arr;
}