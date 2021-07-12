/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbertoni <wbertoni@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 17:55:39 by Wblech            #+#    #+#             */
/*   Updated: 2020/04/09 15:10:40 by wbertoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <stdarg.h>
# include "libft.h"

typedef enum	e_names
{
	value,
	size_precision,
	flag,
	width,
	size_zeroflag,
	size_value,
	type_char,
	isneg,
	isnull
}				t_names;

typedef struct	s_printf
{
	char		*value;
	int			size_precision;
	int			flag;
	int			width;
	int			size_zeroflag;
	int			size_value;
	int			type_char;
	int			isneg;
	int			nbr_size;
	int			isnull;
}				t_printf;

t_printf		*create_printf(void);
void			update_value(t_printf *elem, char *str);
void			update_option(t_printf *elem, t_names name, int opt);
void			del_elem(t_printf *elem);
void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_putstr_null(char *str);
void			ft_check_neg_sign(t_printf *elem);
void			ft_zerotowidth(t_printf *elem);
int				ft_check_flag_zero(char *str);
char			*ft_strupper(char *str);
char			*ft_uitoa_base(uintmax_t n, int base);
int				ft_str_nbr_size(char *str);
char			*ft_precision(t_printf *estrutura);
char			*ft_width(t_printf *estrutura);
char			*ft_zeroflag(t_printf *estrutura);
unsigned int	ft_getnumber(t_printf *elem, char *str, va_list *args,
int isprecision);
unsigned int	ft_getnbrsize(unsigned int nbr);
int				ft_print_percent_rule(char *str, va_list *args);
int				ft_printf(const char *str, ...);
int				ft_getinfo(char *str, t_printf *elem, va_list *args);
void			ft_getvalue(t_printf *elem, va_list *args);

int				g_counter;

#endif
