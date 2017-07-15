/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 23:02:39 by jtrujill          #+#    #+#             */
/*   Updated: 2017/06/10 17:39:07 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	ft_svalid(char *str)
{
	char	c;

	c = ft_tolower(str[ft_strlen(str) - 1]);
	if (ft_char_count(str, '+') > 0)
		return (0);
	if ((c == 'd') || (c == 'i') || (c == 'o') || (c == 'x') \
		|| (c == 'p'))
		return (1);
	else
		return (0);
}

int			ft_space(char *str, char *todo, int start)
{
	int		i;
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	i = 0;
	if ((ft_char_count(todo, ' ') > 0) && (ft_svalid(todo) == 1))
	{
		while (str[start] == ' ')
			start++;
		i = ft_atoi(&str[start]);
		if (i < 0)
			return (0);
		tmp = ft_strncpy(ft_strnew(start), (const char *)str, start);
		tmp2 = ft_strdup(&str[start]);
		tmp3 = ft_strjoin(" ", tmp2);
		ft_strdel(&tmp2);
		tmp2 = ft_strjoin(tmp, tmp3);
		ft_strdel(&tmp);
		ft_strdel(&tmp3);
		ft_strinsert(tmp2, "", 3);
		ft_strdel(&tmp2);
	}
	return (0);
}
