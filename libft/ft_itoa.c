/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbertoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:35:31 by wbertoni          #+#    #+#             */
/*   Updated: 2020/01/28 18:16:16 by wbertoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countsize(int n)
{
	size_t	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n != 0)
	{
		n /= 10;
		++count;
	}
	return (count);
}

static int	ft_isneg(int n)
{
	if (n < 0)
		return (-1);
	return (1);
}

char	*ft_itoa(int n)
{
	int		neg;
	size_t	i;
	char	*str;
	long	nbr;

	nbr = n;
	i = 0;
	neg = ft_isneg(nbr);
	if (neg == -1)
		i = 1;
	nbr *= neg;
	i += ft_countsize(nbr);
	str = ft_calloc(sizeof(char), (i + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		str[i] = '0';
	while (nbr > 0)
	{
		str[i--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (neg == -1)
		str[i] = '-';
	return (str);
}
