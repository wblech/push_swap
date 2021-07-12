/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getinfo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbertoni <wbertoni@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 12:00:47 by wbertoni          #+#    #+#             */
/*   Updated: 2020/04/21 13:39:59 by wbertoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** Function: ft_create_flag
** -------------------------
** Description: Update the value "flag" inside the structure elem.
** If the flag is '0' but the next char is the flag '-', the char '-'
** will be save in the flag value inside the structure.
**
** elem: the pointer to the structure
** str: the string with the flag
** i: the index where the flag is inside the string
**
** Return: how many positions the flag use inside the string
*/

static int		ft_create_flag(t_printf *elem, char *str, int i)
{
	int j;

	j = 1;
	if (str[i] == '0')
	{
		while (str[i + j] != '.' && str[i + j] != 'i' && str[i + j] != 'd'
		&& str[i + j] != 'u' && str[i + j] != 'x' && str[i + j] != 'X' &&
		str[i + j] != 'p' && str[i + j] != 's' && str[i + j] != 'c'
		&& str[i + j] != '%')
		{
			if (str[i + j] == '-')
			{
				update_option(elem, flag, '-');
				return ((i + j) + 1);
			}
			j++;
		}
		update_option(elem, flag, str[i++]);
	}
	else
		update_option(elem, flag, str[i++]);
	return (i);
}

static int		ft_create_flag_size(t_printf *elem, char *str, int i,
va_list *args)
{
	int nbr;

	nbr = 0;
	if (elem->flag == '0')
		update_option(elem, size_zeroflag, (nbr = ft_getnumber(elem, &str[i],
		args, 0)));
	else
		update_option(elem, width, (nbr = ft_getnumber(elem, &str[i], args,
		0)));
	i += (str[i] == '*') ? 1 : ft_str_nbr_size(&str[i]);
	return (i);
}

static int		ft_create_precision(t_printf *elem, char *str, int i,
va_list *args)
{
	int nbr;

	nbr = 0;
	i++;
	if (ft_isdigit(str[i]) || str[i] == '*')
	{
		update_option(elem, size_precision, (nbr = ft_getnumber(elem, &str[i],
		args, 1)));
		i += (str[i] == '*') ? 1 : ft_str_nbr_size(&str[i]);
	}
	else
		update_option(elem, size_precision, 0);
	return (i);
}

static void		ft_create_value(t_printf *elem, char *str, va_list *args, int i)
{
	if (str[i] == 'c' || str[i] == 's' || str[i] == 'p' || str[i] == 'd' ||
		str[i] == 'i' || str[i] == 'u' || str[i] == 'x' || str[i] == 'X')
	{
		update_option(elem, type_char, str[i]);
		ft_getvalue(elem, args);
	}
	else if (str[i] == '%')
	{
		update_option(elem, type_char, '%');
		update_value(elem, ft_strdup("%"));
	}
	else
	{
		update_option(elem, type_char, 'y');
		update_value(elem, ft_strdup(""));
	}
}

int				ft_getinfo(char *str, t_printf *elem, va_list *args)
{
	int i;

	i = 1;
	if (str[i] == '0' || str[i] == '-')
		i = ft_create_flag(elem, str, i);
	if (ft_isdigit(str[i]) || str[i] == '*')
		i = ft_create_flag_size(elem, str, i, args);
	i += ft_check_flag_zero(&str[i]);
	if (ft_isdigit(str[i]) || str[i] == '*')
		i = ft_create_flag_size(elem, str, i, args);
	if (str[i] == '.')
	{
		i = ft_create_precision(elem, str, i, args);
		if (elem->flag == 48 && elem->size_zeroflag != 0 &&
		elem->size_precision >= 0)
			ft_zerotowidth(elem);
	}
	ft_create_value(elem, str, args, i);
	return (i);
}
