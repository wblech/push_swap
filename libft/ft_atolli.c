#include "libft.h"

long long int	ft_atolli(const char *str)
{
	unsigned long long int	nbr;
	int						index;
	int						sign;

	nbr = 0;
	sign = 1;
	index = 0;
	while (ft_isspace(str[index]))
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign = -1;
		else
			sign = 1;
		index++;
	}
	while (ft_isdigit(str[index]))
	{
		nbr *= 10;
		nbr += str[index++] - '0';
	}
	return ((long long int)(nbr * sign));
}
