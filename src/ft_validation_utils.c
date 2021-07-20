#include "push_swap.h"

bool	is_valid_int(long long int nbr)
{
	long long int	max_int;
	long long int	min_int;
	bool			is_valid;

	max_int = 2147483647;
	min_int = -2147483648;
	is_valid = true;
	if (nbr > max_int || nbr < min_int)
		is_valid = false;
	return (is_valid);
}

bool	is_sorted(int *arr, int size, int top)
{
	int		i;
	int		last_pos;
	bool	is_sorted;

	i = top;
	last_pos = size - 1;
	is_sorted = true;
	while (i < last_pos && is_sorted)
	{
		if (arr[i] >= arr[i + 1])
			is_sorted = false;
		i++;
	}
	return (is_sorted);
}
