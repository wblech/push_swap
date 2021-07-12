/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbertoni <wbertoni@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:09:29 by wbertoni          #+#    #+#             */
/*   Updated: 2020/04/09 14:54:25 by wbertoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_create_width_bigger(t_printf *elem, int dif, char *new)
{
	int i;

	i = 0;
	ft_memset(new, ' ', elem->width);
	while (elem->value[i] != '\0')
	{
		if (elem->flag == '-')
			new[i] = elem->value[i];
		else
			new[dif] = elem->value[i];
		dif++;
		i++;
	}
}

static void	ft_create_width_smaller(t_printf *elem, char *new)
{
	int i;

	i = 0;
	while (elem->value[i] != '\0')
	{
		new[i] = elem->value[i];
		i++;
	}
}

char		*ft_width(t_printf *elem)
{
	int		dif;
	int		i;
	char	*new;

	i = 0;
	if (elem->isneg && elem->size_precision < 0)
	{
		update_value(elem, ft_strjoin("-", elem->value));
		update_option(elem, size_value, (int)ft_strlen(elem->value));
	}
	dif = elem->size_value - elem->width;
	if (dif < 0)
	{
		new = (char *)ft_calloc((elem->width + 1), 1);
		dif *= -1;
		ft_create_width_bigger(elem, dif, new);
	}
	else
	{
		new = (char *)ft_calloc((elem->size_value + 1), 1);
		ft_create_width_smaller(elem, new);
	}
	return (new);
}
