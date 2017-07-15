/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 23:01:45 by jtrujill          #+#    #+#             */
/*   Updated: 2017/06/10 17:52:14 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	hash_help(char *todo, int i)
{
	if ((i == 0) && (ft_tolower(todo[ft_strlen(todo) - 1]) == 'o'))
	{
		if (todo[ft_strlen(todo) - 2] == '.')
			return (1);
		else if ((todo[ft_strlen(todo) - 2] == '0')
			&& (todo[ft_strlen(todo) - 3] == '.'))
			return (1);
		else
			return (0);
	}
	return (1);
}

static int	hash_help2(char *str, char *todo, int start, int i)
{
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	while (str[start] == ' ')
		start++;
	i = ft_atoi(&str[start]);
	if (hash_help(todo, i) == 0)
		return (0);
	tmp = ft_strncpy(ft_strnew(start), (const char *)str, start);
	tmp2 = ft_strncpy(ft_strnew(ft_strlen(&str[start])),
		(const char *)&str[start], (ft_strlen(&str[start])));
	if (todo[ft_strlen(todo) - 1] == 'o')
		tmp3 = ft_strjoin("0", tmp2);
	else if (todo[ft_strlen(todo) - 1] == 'x')
		tmp3 = ft_strjoin("0x", tmp2);
	else if (todo[ft_strlen(todo) - 1] == 'X')
		tmp3 = ft_strjoin("0X", tmp2);
	ft_strdel(&tmp2);
	tmp2 = ft_strjoin(tmp, tmp3);
	ft_strdel(&tmp);
	ft_strdel(&tmp3);
	ft_strinsert(tmp2, "", 3);
	ft_strdel(&tmp2);
	return (1);
}

int			ft_hash(char *str, char *todo, int start)
{
	int		i;

	i = 0;
	if ((str[start] == '0') || (str[start] == '\0'))
	{
		if (todo[ft_strlen(todo) - 1] != 'o')
			return (0);
	}
	if (ft_char_count(todo, '#') > 0)
		return (hash_help2(str, todo, start, i));
	return (0);
}
