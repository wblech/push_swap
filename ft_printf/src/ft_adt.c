/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbertoni <wbertoni@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:18:45 by wbertoni          #+#    #+#             */
/*   Updated: 2020/04/09 12:28:09 by wbertoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_printf	*create_printf(void)
{
	int			i;
	int			enum_size;
	t_printf	*elem;

	i = 2;
	enum_size = 9;
	elem = malloc(sizeof(t_printf));
	if (!elem)
		return (NULL);
	elem->value = NULL;
	elem->size_precision = (int)-1;
	while (i < enum_size)
		update_option(elem, i++, 0);
	return (elem);
}

void		update_value(t_printf *elem, char *str)
{
	char *tmp;

	if (elem->value != NULL && elem->type_char != 's')
	{
		tmp = elem->value;
		elem->value = str;
		free(tmp);
	}
	else
		elem->value = (str != NULL) ? str : ft_strdup("(null)");
}

void		update_option(t_printf *elem, t_names name, int opt)
{
	if (name == flag)
		elem->flag = opt;
	if (name == width)
		elem->width = opt;
	if (name == size_zeroflag)
		elem->size_zeroflag = opt;
	if (name == size_precision)
		elem->size_precision = opt;
	if (name == size_value)
		elem->size_value = opt;
	if (name == type_char)
		elem->type_char = opt;
	if (name == isneg)
		elem->isneg = opt;
	if (name == isnull)
		elem->isnull = opt;
}

void		del_elem(t_printf *elem)
{
	if (elem->value != NULL)
		elem->value = NULL;
	free(elem);
}
