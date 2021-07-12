/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zeroflag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbertoni <wbertoni@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 15:35:02 by wbertoni          #+#    #+#             */
/*   Updated: 2020/04/09 15:07:54 by wbertoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_zeroflag_bigger(t_printf *elem, int dif, char *new)
{
	int i;

	i = 0;
	ft_memset(new, '0', elem->size_zeroflag);
	while (elem->value[i] != '\0')
	{
		new[(elem->isneg) ? dif + 1 : dif] = elem->value[i];
		dif++;
		i++;
	}
}

char		*ft_zeroflag(t_printf *elem)
{
	int		dif;
	int		i;
	int		t;
	char	*new;

	i = 0;
	t = 0;
	dif = elem->size_value - elem->size_zeroflag;
	if (dif <= 0)
	{
		new = (char *)ft_calloc((elem->size_zeroflag + 1), 1);
		dif *= -1;
		ft_zeroflag_bigger(elem, dif, new);
	}
	else
	{
		i = (elem->isneg) ? i + 1 : 0;
		new = (char *)ft_calloc((elem->size_value + 1), 1);
		while (elem->value[t] != '\0')
			new[i++] = elem->value[t++];
	}
	if (elem->isneg)
		new[0] = '-';
	return (new);
}
