/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbertoni <wbertoni@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 14:34:50 by wbertoni          #+#    #+#             */
/*   Updated: 2020/04/09 14:34:51 by wbertoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*createstr(char *a, uintmax_t n, int base, int size)
{
	if (n == 0)
	{
		a[0] = '0';
		return (a);
	}
	while (size >= 0)
	{
		if (n % base >= 10 && base > 10)
			a[size - 1] = (n % base) - 10 + 'a';
		else
			a[size - 1] = (n % base) + '0';
		n /= base;
		size--;
	}
	return (a);
}

char			*ft_uitoa_base(uintmax_t n, int base)
{
	char		*a;
	int			size;
	uintmax_t	nbr;

	nbr = n;
	size = 0;
	if (n != 0)
	{
		while (nbr /= base)
			size++;
	}
	else
		size = 1;
	if (n != 0)
		size++;
	a = ft_newstr(size + 1);
	if (a == NULL)
		return (NULL);
	a[ft_strlen(a)] = '\0';
	return (createstr(a, n, base, size));
}
