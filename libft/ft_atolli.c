#include "libft.h"

long long int   ft_atolli(const char *str)
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
		sign = (str[index] == '-') ? -1 : 1;
		index++;
	}
	while (ft_isdigit(str[index]))
	{
		nbr *= 10;
		nbr += str[index++] - '0';
	}
	if (nbr > (unsigned long long int)LONG_MAX && sign == 1)
		return (-1);
	if (nbr > (unsigned long long int)(-LONG_MIN) && sign == -1)
		return (0);
	return ((long long int)(nbr * sign));
}