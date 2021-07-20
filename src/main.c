#include "push_swap.h"

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
	holder = get_valid_holder(argc, argv);
	if (holder != NULL)
	{
		sort(holder);
		free_holder(holder);
	}
	return (0);
}
