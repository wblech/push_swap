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

bool is_valid_int(long long int nbr)
{
    long long int max_int;
    long long int min_int;
    bool is_valid;

    max_int = 2147483647;
    min_int = -2147483648;
    is_valid = true;
    if(nbr > max_int || nbr < min_int)
        is_valid = false;
    return is_valid;
}

static int *convert_to_vint(int size, char const *argv[])
{
    int i;
    int *ret_arr;
    long long int tmp;
    bool is_valid;

    i = 1;
    ret_arr = (int *)malloc(sizeof(int) * size);
    is_valid = true;
    while((i - 1) < size && is_valid)
    {
        if((is_valid = is_valid_int(tmp = ft_atolli(argv[i]))))
            ret_arr[i - 1] = (int)tmp;
        else
        {
            free(ret_arr);
            ret_arr = NULL;
        }
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
        if (arr[i] >= arr[i + 1])
            is_sorted = false;
        i++;
    }
    return is_sorted;
}

void arr_int_cpy(int *dst, int *src, int size)
{
    int i;

    i = 0;
    while(i < size)
    {
        dst[i] = src[i];
        i++;
    }
}

static bool is_duplicated(int *arr, int size, int *sorted)
{
    int i;
    bool is_duplicated;

    is_duplicated = false;
    i = 0;
    arr_int_cpy(sorted, arr, size);
    bubble_sort(sorted, size);
    i = 0;
    while (i < size && !is_duplicated)
    {
        if ((sorted[i] - sorted[i + 1]) == 0)
            is_duplicated = true;
        i++;
    }
    return is_duplicated;
}

int *get_valid_int_arr(int size, char const *argv[], int *sorted)
{
    t_error error;
    int *int_arr;
 
    error = no_error;
    int_arr = NULL;
    if (!validate_is_digit(size, argv))
        ft_error(error = enotdigit);
    if (!error)
    {
        if(!(int_arr = convert_to_vint(size, argv)))
            ft_error(error = emaxint);
    }
    if (error || is_sorted(int_arr, size))
        int_arr = print_error_free_arr(esorted_or_invalid_int, int_arr);
    else if (is_duplicated(int_arr, size, sorted))
        int_arr = print_error_free_arr(eduplicated, int_arr);
    return int_arr;
}