/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 22:47:18 by jtrujill          #+#    #+#             */
/*   Updated: 2017/06/10 17:32:05 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		ft_p(va_list ap, char **s1)
{
	void	*data;
	char	*res;
	char	*tmp;
	char	*tmp2;
	int		i;

	i = 0;
	data = va_arg(ap, void *);
	tmp = ft_strdup("0x");
	res = ft_ulitoa_base((unsigned long)data, 16);
	while (res[i] != '\0')
	{
		res[i] = ft_tolower(res[i]);
		i++;
	}
	tmp2 = ft_strjoin(tmp, res);
	*s1 = ft_strinsert(*s1, tmp2, 1);
	ft_strdel(&tmp);
	ft_strdel(&res);
	ft_strdel(&tmp2);
	return (0);
}
