/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 22:47:05 by jtrujill          #+#    #+#             */
/*   Updated: 2017/06/10 17:36:36 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	ft_zeroprec_o(void *data, char *todo)
{
	if (data == NULL)
	{
		while ((*todo != '.') && (*todo != '\0'))
			todo++;
		if ((*todo == '.') && (*(todo + 1) != '\0'))
		{
			if ((*(todo + 1) == 'o') || (*(todo + 1) == '0'))
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

int			ft_o(va_list ap, char **s1, char *todo)
{
	void			*res;
	char			*tmp;

	res = va_arg(ap, void *);
	todo[ft_strlen(todo) - 1] = 'o';
	if (ft_zeroprec_o(res, todo) == 1)
	{
		*s1 = ft_strinsert(*s1, " ", 1);
		return (0);
	}
	else if (ft_zeroprec_o(res, todo) == -1)
	{
		*s1 = ft_strinsert(*s1, "", 1);
		return (0);
	}
	tmp = ft_umitoa_base((uintmax_t)res, 8);
	*s1 = ft_strinsert(*s1, tmp, 1);
	ft_strdel(&tmp);
	return (0);
}
