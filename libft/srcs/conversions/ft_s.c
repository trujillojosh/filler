/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 22:47:30 by jtrujill          #+#    #+#             */
/*   Updated: 2017/06/10 17:23:36 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		ft_s(va_list ap, char **s1, int prec)
{
	char	*var;
	char	*tmp;

	var = va_arg(ap, char *);
	if (!var)
	{
		*s1 = ft_strinsert(*s1, "(null)", 1);
		return (0);
	}
	else if (((int)ft_strlen(var) > prec) && (prec != -1))
	{
		tmp = ft_strnew(ft_strlen(var));
		tmp = ft_strncpy(tmp, var, prec);
		*s1 = ft_strinsert(*s1, tmp, 1);
		free(tmp);
	}
	else
		*s1 = ft_strinsert(*s1, var, 1);
	return (0);
}
