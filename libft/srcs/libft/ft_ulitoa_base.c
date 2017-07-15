/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulitoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 01:43:12 by jtrujill          #+#    #+#             */
/*   Updated: 2017/06/10 18:42:01 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int		ft_ulint_len_ext(unsigned long nb, int base)
{
	int	i;

	i = 0;
	while ((nb / base) != 0)
	{
		i++;
		nb = nb / base;
	}
	i++;
	return (i);
}

char			*ft_ulitoa_base(unsigned long value, int base)
{
	int		i;
	char	*re;

	i = 1;
	if (base == 10)
		return (ft_itoa_ul(value));
	i = ft_ulint_len_ext(value, base);
	re = (char *)malloc(sizeof(char) * (i + 1));
	re[i] = '\0';
	i--;
	while (i >= 0)
	{
		if ((value % base) > 9)
			re[i] = (value % base) + 55;
		else
			re[i] = (value % base) + 48;
		value = value / base;
		i--;
	}
	return (re);
}
