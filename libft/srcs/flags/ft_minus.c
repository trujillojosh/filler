/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 23:02:25 by jtrujill          #+#    #+#             */
/*   Updated: 2017/06/10 17:37:39 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		ft_minus(char *str, char *todo, int start)
{
	int		i;
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	if (ft_char_count(todo, '-') > 0)
	{
		i = start;
		while (str[i] == ' ')
			i++;
		if (i == 0)
			return (0);
		tmp = ft_strncpy(ft_strnew(start), str, start);
		tmp2 = ft_memset(ft_strnew(i - start), ' ', (i - start));
		tmp3 = ft_strjoin(&str[i], tmp2);
		ft_strdel(&tmp2);
		tmp2 = ft_strjoin(tmp, tmp3);
		ft_strdel(&tmp);
		ft_strinsert(tmp2, "", 3);
		ft_strdel(&tmp3);
		ft_strdel(&tmp2);
	}
	return (0);
}
