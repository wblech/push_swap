#include "push_swap.h"

bool has_more_than_11_char(int size, char const *nbr[])
{
	int i;

	i = 0;
	while(i < size)
	{
		if(ft_strlen(nbr[i + 1]) > 11)
			return true;
		i++;
	}
	return false;
}

void	sort(t_holder *holder)
{
	if (holder->a_stack->size <= 5)
		small_sort(holder);
	else
		big_sort(holder);
}

int	main(int argc, char const *argv[])
{
	t_holder	*holder;

	if (argc < 2)
		return (0);
	if(has_more_than_11_char(argc - 1, argv))
	{
		ft_putstr_fd("Error\n", STDOUT_FILENO);
		return (0);
	}
	holder = get_valid_holder(argc, argv);
	if (holder != NULL)
	{
		sort(holder);
		free_holder(holder);
	}
	return (0);
}
