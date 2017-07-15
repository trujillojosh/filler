/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_dispatch.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 22:24:02 by jtrujill          #+#    #+#             */
/*   Updated: 2017/06/10 19:43:43 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		cast_helper(char *todo, char c)
{
	if (ft_char_count(todo, 'h') > 0)
	{
		if (ft_char_count(todo, 'h') > 1)
		{
			if ((c == 'd') || (c == 'i'))
				return (2);
			return (3);
		}
		if ((c == 'd') || (c == 'i'))
			return (4);
		return (5);
	}
	else if (ft_char_count(todo, 'l') > 1)
	{
		if ((c == 'd') || (c == 'i'))
			return (8);
		return (9);
	}
	if ((c == 'd') || (c == 'i'))
		return (6);
	return (7);
}

static int		cast_find(char *todo, char c)
{
	if (c == 'D')
		return (8);
	else if (c == 'U')
		return (9);
	c = ft_tolower(c);
	if (ft_char_count(todo, 'j') > 0)
	{
		if ((c == 'd') || (c == 'i'))
			return (10);
		return (11);
	}
	else if (ft_char_count(todo, 'z') > 0)
		return (12);
	if ((ft_char_count(todo, 'h') > 0) || (ft_char_count(todo, 'l') > 0))
		return (cast_helper(todo, c));
	if ((c == 'd') || (c == 'i'))
		return (0);
	return (1);
}

static char		*dispatch_help(void *nb, int i, int base)
{
	if (i == 0)
		return (ft_itoa_m((int)nb));
	else if (i == 1)
		return (ft_umitoa_base((unsigned int)nb, base));
	else if (i == 2)
		return (ft_itoa_m((char)nb));
	else if (i == 3)
		return (ft_umitoa_base((unsigned char)nb, base));
	else if (i == 4)
		return (ft_itoa_m((short)nb));
	else if (i == 5)
		return (ft_umitoa_base((unsigned short)nb, base));
	else if (i == 6)
		return (ft_itoa_m((long)nb));
	else if (i == 7)
		return (ft_umitoa_base((unsigned long)nb, base));
	else if (i == 8)
		return (ft_umitoa_base((long long)nb, base));
	else if (i == 9)
		return (ft_umitoa_base((unsigned long long)nb, base));
	else if (i == 10)
		return (ft_umitoa_base((intmax_t)nb, base));
	else if (i == 11)
		return (ft_umitoa_base((uintmax_t)nb, base));
	return (ft_umitoa_base((size_t)nb, base));
}

char			*ft_itoa_dispatch(void *nb, char *todo, int base)
{
	char	c;
	int		i;
	char	*res;
	char	*tmp;
	int		neg;

	c = todo[ft_strlen(todo) - 1];
	i = cast_find(todo, c);
	neg = 0;
	if ((intmax_t)nb < 0)
		neg = 1;
	res = dispatch_help(nb, i, base);
	if ((neg == 1) && (base == 10) && (res[0] != '-'))
	{
		if ((i == 12) && ((c == 'i') || (c == 'd')))
			i = 2;
		if ((i == 1) || (i == 3) || (i == 5) || (i == 7) ||
				(i == 9) || (i == 11) || (i == 12))
			return (res);
		tmp = ft_strjoin("-", res);
		ft_strdel(&res);
		return (tmp);
	}
	return (res);
}
