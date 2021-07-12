/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers_second.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbertoni <wbertoni@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 12:31:30 by wbertoni          #+#    #+#             */
/*   Updated: 2020/04/09 14:21:03 by wbertoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_check_neg_sign(t_printf *elem)
{
	char *has_sign;

	if (elem->isneg)
	{
		has_sign = ft_strchr(elem->value, '-');
		if (!(has_sign))
			ft_putchar('-');
	}
}

void	ft_zerotowidth(t_printf *elem)
{
	update_option(elem, flag, 0);
	update_option(elem, width, elem->size_zeroflag);
	update_option(elem, size_zeroflag, 0);
}

int		ft_check_flag_zero(char *str)
{
	int i;

	i = 0;
	while (str[i] == '-' || str[i] == '0')
		i++;
	return (i);
}
