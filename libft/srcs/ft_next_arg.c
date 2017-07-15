/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 17:44:26 by jtrujill          #+#    #+#             */
/*   Updated: 2017/06/10 17:21:56 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	type_check(char *type)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strdup("*$L'");
	while (type[i] != '\0')
	{
		if (ft_strchr(tmp, type[i]) != NULL)
		{
			ft_strdel(&tmp);
			return (-1);
		}
		i++;
	}
	ft_strdel(&tmp);
	return (0);
}

static char	*ft_find_type(char *str)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	while ((*str != '%') && (*str != '\0'))
		str++;
	if (*str == '%')
		str++;
	while (ft_is_over(str[i], 2))
		i++;
	ret = ft_strnew(i + 1);
	while (j < i)
	{
		ret[j] = *str;
		j++;
		str++;
	}
	ret[j] = '\0';
	return (ret);
}

static int	ft_dispatch(va_list ap, char **todo, char **str)
{
	char	c;

	if (ft_strlen(*todo) > 0)
		c = (*todo)[ft_strlen(*todo) - 1];
	else
		return (-1);
	if ((c == 's') || c == 'S')
		return (ft_s(ap, str, -1));
	else if ((c == 'd') || (c == 'i') || (c == 'D'))
		return (ft_d(ap, str, *todo));
	else if ((c == 'c') || (c == 'C'))
		return (ft_c(ap, str));
	else if (c == '%')
		return (ft_percent(str));
	else if (c == 'p')
		return (ft_p(ap, str));
	else if ((c == 'o') || (c == 'O'))
		return (ft_o(ap, str, *todo));
	else if ((c == 'u') || (c == 'U'))
		return (ft_u(ap, str, *todo));
	else if (c == 'x')
		return (ft_x(ap, str, *todo));
	else if (c == 'X')
		return (ft_up_x(ap, str, *todo));
	return (-1);
}

static int	ft_flags(va_list ap, char **todo, char **str)
{
	int		i;
	int		k;
	int		prec;

	i = 0;
	k = 0;
	*str = ft_strinsert(*str, "", 0);
	i = ft_strlen(ft_strinsert("", "", 2));
	prec = find_precision(*todo);
	if (ft_strlen(*todo) == 0)
		return (0);
	else if (ft_tolower((*todo)[ft_strlen(*todo) - 1]) == 's')
		ft_s(ap, str, prec);
	else if ((k = ft_dispatch(ap, todo, str)) < 0)
		return (k);
	if ((prec >= 0) && ((*todo)[ft_strlen(*todo) - 1] != 's'))
		ft_precision(ft_strinsert("", "", 2), i, *todo, prec);
	ft_width(ft_strinsert("", "", 2), *todo, i, k);
	ft_plus(ft_strinsert("", "", 2), *todo, i);
	ft_space(ft_strinsert("", "", 2), *todo, i);
	ft_0(ft_strinsert("", "", 2), *todo, i, prec);
	ft_hash(ft_strinsert("", "", 2), *todo, i);
	ft_minus(ft_strinsert("", "", 2), *todo, i);
	*str = ft_strinsert(*str, "", 0);
	return (k);
}

int			ft_next_arg(va_list ap, char **str)
{
	char	*type;
	int		res;

	type = ft_find_type(*str);
	if (type_check(type) < 0)
		return (-1);
	res = ft_flags(ap, &type, str);
	if (res < 0)
	{
		ft_strdel(&type);
		return (-1);
	}
	ft_strdel(&type);
	return (res);
}
