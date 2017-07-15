/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 17:03:07 by jtrujill          #+#    #+#             */
/*   Updated: 2017/06/10 17:41:42 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int			find_precision(char *todo)
{
	int		i;
	char	type;

	i = 0;
	if (ft_strlen(todo) > 0)
		type = todo[ft_strlen(todo) - 1];
	if (ft_char_count(todo, '.') > 0)
	{
		while ((*todo != '.') && (*todo != '\0'))
			todo++;
		if ((*(todo + 1) != '\0') && (*todo == '.'))
			todo++;
		if (*todo == type)
			return (0);
		i = ft_atoi(todo);
		if (ft_strchr("sSdDioOuUxX", (int)type) != NULL)
			return (i);
		else
			return (-2);
	}
	return (-1);
}

static void	prec_helper(char *str, int start, int prec)
{
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	if (start > 0)
	{
		tmp = ft_strncpy(ft_strnew(start), (const char *)str, start);
		tmp3 = ft_memset(ft_strnew(prec), '0', prec);
		tmp2 = ft_strjoin(tmp3, &str[start]);
		ft_strdel(&tmp3);
		tmp3 = ft_strjoin(tmp, tmp2);
	}
	else
	{
		tmp = ft_strdup(str);
		tmp2 = ft_memset(ft_strnew(prec), '0', prec);
		tmp3 = ft_strjoin(tmp2, tmp);
	}
	ft_strinsert(tmp3, "", 3);
	ft_strdel(&tmp);
	ft_strdel(&tmp2);
	ft_strdel(&tmp3);
}

int			ft_precision(char *str, int start, char *todo, int prec)
{
	prec -= (int)ft_strlen(&str[start]);
	if ((prec == -1) && (todo[ft_strlen(todo) - 1] != '%') &&
			(ft_strlen(&str[start]) <= 1))
	{
		ft_strclr(&str[start]);
		ft_strinsert(str, "", 3);
	}
	if (prec > 0)
	{
		if ((str[start] == '+') || (str[start] == '-'))
		{
			start++;
			prec++;
		}
		prec_helper(str, start, prec);
	}
	return (0);
}
