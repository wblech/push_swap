/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbertoni <wbertoni@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 20:11:44 by wbertoni          #+#    #+#             */
/*   Updated: 2020/04/09 14:31:46 by wbertoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

unsigned int	ft_getnumber(t_printf *elem, char *str, va_list *args,
int isprecision)
{
	int		size;
	int		nbr;
	char	*new;

	size = 0;
	if (str[size] == '*')
	{
		nbr = va_arg(*args, int);
		if (!isprecision && nbr < 0)
		{
			update_option(elem, flag, '-');
			nbr *= -1;
			update_option(elem, width, nbr);
		}
		return (nbr);
	}
	size = ft_str_nbr_size(&str[size]);
	new = (char *)ft_calloc(size + 1, 1);
	ft_strncpy(new, str, size);
	nbr = (unsigned int)ft_atoi(new);
	free(new);
	return (nbr);
}

unsigned int	ft_getnbrsize(unsigned int nbr)
{
	unsigned int i;

	i = 1;
	if (nbr == 0)
		return (0);
	while ((nbr /= 10) > 0)
		i++;
	return (i);
}

static void		ft_polish(t_printf *elem)
{
	if (elem->size_precision >= 0)
	{
		if (elem->type_char == 'p')
			update_option(elem, size_value, (int)ft_strlen(elem->value) - 2);
		else
			update_option(elem, size_value, (int)ft_strlen(elem->value) +
			elem->isneg);
		update_value(elem, ft_precision(elem));
	}
	if (elem->width > 0)
	{
		update_option(elem, size_value, (int)ft_strlen(elem->value));
		update_value(elem, ft_width(elem));
	}
	if (elem->size_precision < 0 && elem->flag == '0')
	{
		update_option(elem, size_value, (int)ft_strlen(elem->value) +
		elem->isneg);
		update_value(elem, ft_zeroflag(elem));
	}
}

int				ft_print_percent_rule(char *str, va_list *args)
{
	t_printf	*elem;
	int			i;

	i = 0;
	elem = create_printf();
	i = ft_getinfo(str, elem, args);
	ft_polish(elem);
	ft_check_neg_sign(elem);
	if (elem->isnull)
		ft_putstr_null(elem->value);
	else
		ft_putstr(elem->value);
	del_elem(elem);
	return (i);
}

int				ft_printf(const char *str, ...)
{
	int		i;
	va_list args;
	int		counter;

	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			i += ft_print_percent_rule(&((char *)str)[i], &args);
		else
			ft_putchar(str[i]);
		i += (str[i] != '\0') ? 1 : 0;
	}
	counter = g_counter;
	g_counter = 0;
	return (counter);
}
