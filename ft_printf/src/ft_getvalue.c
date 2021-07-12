/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getvalue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbertoni <wbertoni@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 16:48:26 by wbertoni          #+#    #+#             */
/*   Updated: 2020/04/09 14:28:27 by wbertoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		ft_getvalue_d_i(t_printf *elem, va_list *args)
{
	intmax_t intvalue;

	intvalue = va_arg(*args, int);
	if (intvalue < 0)
	{
		update_option(elem, isneg, 1);
		intvalue *= -1;
	}
	if (intvalue == 2147483648)
		update_value(elem, ft_strdup("2147483648"));
	else
		update_value(elem, ft_itoa(intvalue));
}

static void		ft_getvalue_char(t_printf *elem, va_list *args)
{
	int charvalue;

	charvalue = va_arg(*args, int);
	if (charvalue != 0)
		update_value(elem, ft_chartostr(charvalue));
	else
	{
		update_value(elem, ft_strdup("*"));
		update_option(elem, isnull, 1);
	}
}

void			ft_getvalue(t_printf *elem, va_list *args)
{
	int i;

	i = 0;
	if (elem->type_char == 's')
		update_value(elem, va_arg(*args, char *));
	if (elem->type_char == 'd' || elem->type_char == 'i')
		ft_getvalue_d_i(elem, args);
	if (elem->type_char == 'c')
		ft_getvalue_char(elem, args);
	if (elem->type_char == 'x')
		update_value(elem, ft_uitoa_base(va_arg(*args, unsigned int), 16));
	if (elem->type_char == 'X')
		update_value(elem, ft_strupper(ft_uitoa_base(va_arg(*args, unsigned int)
		, 16)));
	if (elem->type_char == 'u')
		update_value(elem, ft_uitoa_base(va_arg(*args, unsigned int), 10));
	if (elem->type_char == 'p')
		update_value(elem, ft_strjoin("0x", ft_uitoa_base(va_arg(*args,
		uintptr_t), 16)));
}
