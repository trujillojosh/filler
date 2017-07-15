/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 22:46:21 by jtrujill          #+#    #+#             */
/*   Updated: 2017/06/10 19:26:02 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	printf_help(int k)
{
	int		i;

	i = ft_strlen(ft_strinsert("", "", 2)) + k;
	if ((i - k) == 0)
		ft_putchar(0);
	else
		ft_putstr(ft_strinsert("", "", 2));
	ft_strinsert("", "", 4);
	return (i);
}

int			ft_printf(const char *input, ...)
{
	va_list		ap;
	int			i;
	int			k;
	int			l;
	char		*str;

	l = 0;
	k = 0;
	if ((i = ft_char_count((char *)input, '%')) == 0)
	{
		ft_putstr(input);
		return (ft_strlen(input));
	}
	str = ft_strdup(input);
	va_start(ap, input);
	while (i-- >= 0)
	{
		if ((l = ft_next_arg(ap, &str)) == 1)
			k++;
		else if (l == -1)
			return (0);
	}
	va_end(ap);
	return (printf_help(k));
}
