/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 23:01:10 by jtrujill          #+#    #+#             */
/*   Updated: 2017/06/10 17:36:04 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	ft_zeroprec_x(void *data, char *todo)
{
	if (data == NULL)
	{
		while ((*todo != '.') && (*todo != '\0'))
			todo++;
		if ((*todo == '.') && (*(todo + 1) != '\0'))
		{
			if ((*(todo + 1) == 'x') || (*(todo + 1) == '0'))
			{
				if (ft_isdigit(*(todo - 1)) == 1)
					return (1);
				else
					return (-1);
			}
		}
	}
	return (0);
}

int			ft_x(va_list ap, char **s1, char *todo)
{
	void			*res;
	char			*tmp;
	int				i;

	i = 0;
	res = va_arg(ap, void *);
	if ((ft_zeroprec_x(res, todo) == 1) || (ft_zeroprec_x(res, todo) == -1))
	{
		if (ft_zeroprec_x(res, todo) == 1)
			*s1 = ft_strinsert(*s1, " ", 1);
		else
			*s1 = ft_strinsert(*s1, "", 1);
		return (0);
	}
	tmp = ft_itoa_dispatch(res, todo, 16);
	while (tmp[i] != '\0')
	{
		tmp[i] = ft_tolower(tmp[i]);
		i++;
	}
	*s1 = ft_strinsert(*s1, tmp, 1);
	ft_strdel(&tmp);
	return (0);
}
