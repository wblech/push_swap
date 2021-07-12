/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbertoni <wbertoni@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 16:45:52 by wbertoni          #+#    #+#             */
/*   Updated: 2020/04/09 12:33:09 by wbertoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
	g_counter++;
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	if (!str)
		return ;
	while (str[i] != '\0')
		ft_putchar(str[i++]);
}

void	ft_putstr_null(char *str)
{
	int i;

	i = 0;
	if (str[i] == '*')
	{
		ft_putchar('\0');
		i = 1;
		ft_putstr(&str[i]);
	}
	else
	{
		while (str[i] != '*' && str[i] != '\0')
			ft_putchar(str[i++]);
		ft_putchar('\0');
	}
}

char	*ft_strupper(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}

int		ft_str_nbr_size(char *str)
{
	int size;

	size = 0;
	while (ft_isdigit(str[size]))
		size++;
	return (size);
}
