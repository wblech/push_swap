#include "push_swap.h"

static	void	bubble_swap(int *xp, int *yp)
{
	int	temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
				bubble_swap(&arr[j], &arr[j + 1]);
			j++;
		}
		j = 0;
		i++;
	}
}
