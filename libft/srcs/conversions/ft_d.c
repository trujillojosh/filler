/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 22:46:56 by jtrujill          #+#    #+#             */
/*   Updated: 2017/06/10 17:36:24 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	ft_zeroprec_d(void *data, char *todo)
{
	if (data == NULL)
	{
		while ((*todo != '.') && (*todo != '\0'))
			todo++;
		if ((*todo == '.') && (*(todo + 1) != '\0'))
		{
			if ((*(todo + 1) == 'd') || (*(todo + 1) == '0'))
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

int			ft_d(va_list ap, char **s1, char *todo)
{
	void	*digit;
	char	*tmp;

	digit = va_arg(ap, void *);
	if (todo[ft_strlen(todo) - 1] == 'i')
		todo[ft_strlen(todo) - 1] = 'd';
	if (ft_zeroprec_d(digit, todo) == 1)
	{
		*s1 = ft_strinsert(*s1, " ", 1);
		return (0);
	}
	else if (ft_zeroprec_d(digit, todo) == -1)
	{
		*s1 = ft_strinsert(*s1, "", 1);
		return (0);
	}
	if (todo[ft_strlen(todo) - 1] == 'D')
		tmp = ft_itoa_m((long long)digit);
	else
		tmp = ft_itoa_dispatch(digit, todo, 10);
	*s1 = ft_strinsert(*s1, tmp, 1);
	ft_strdel(&tmp);
	return (0);
}
