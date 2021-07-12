/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbertoni <wbertoni@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:06:39 by wbertoni          #+#    #+#             */
/*   Updated: 2020/04/09 12:56:48 by wbertoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		ft_create_precision_bigger(t_printf *elem, int dif, int size,
char *new)
{
	int i;

	i = 0;
	dif *= -1;
	size = elem->size_precision + elem->isneg;
	ft_memset(new, '0', size);
	while (elem->value[i] != '\0')
	{
		new[(elem->isneg) ? dif + 2 : dif] = elem->value[i];
		dif++;
		i++;
	}
}

static char		*ft_precision_nbr(t_printf *elem)
{
	int		dif;
	int		i;
	int		t;
	int		size;
	char	*new;

	i = 0;
	t = 0;
	dif = elem->size_value - elem->size_precision;
	if (dif <= 0)
	{
		size = elem->size_precision + elem->isneg;
		new = (char *)ft_calloc((size + 1), 1);
		ft_create_precision_bigger(elem, dif, size, new);
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

static char		*ft_precision_str(t_printf *elem)
{
	int		len;
	char	*new;
	int		i;

	i = 0;
	len = elem->size_precision;
	new = (char *)ft_calloc((len + 1), 1);
	ft_strncpy(new, elem->value, len);
	return (new);
}

static char		*ft_precision_ptr(t_printf *elem)
{
	char *new;

	new = ft_strdup((ft_strchr(elem->value, 'x')) + 1);
	update_value(elem, new);
	return (ft_strjoin("0x", ft_precision_nbr(elem)));
}

char			*ft_precision(t_printf *elem)
{
	int		spec;
	int		size_precision;
	char	*value;

	size_precision = elem->size_precision;
	value = elem->value;
	spec = elem->type_char;
	if (spec == 'd' || spec == 'i' || spec == 'u' || spec == 'x' || spec == 'X')
	{
		if (!(ft_strncmp(value, "0", ft_strlen(value))) && size_precision == 0)
			return (ft_strdup(""));
		else
			return (ft_precision_nbr(elem));
	}
	if (spec == 's')
		return (ft_precision_str(elem));
	if (spec == 'p')
	{
		if (ft_atoi(value) == 0 && size_precision == 0)
			return (ft_strdup("0x"));
		else
			return (ft_precision_ptr(elem));
	}
	return (value);
}
