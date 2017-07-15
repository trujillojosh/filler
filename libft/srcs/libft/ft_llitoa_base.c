/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 01:43:25 by jtrujill          #+#    #+#             */
/*   Updated: 2017/06/10 18:48:37 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	ft_llint_ext(long long nb, long long base)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		i++;
	}
	while ((nb / base) != 0)
	{
		i++;
		nb = nb / base;
	}
	i++;
	return (i);
}

char		*ft_llitoa_base(long long value, long long base)
{
	int		i;
	char	*re;

	i = 1;
	if (base == 10)
		return (ft_itoa_ll(value));
	i = ft_llint_ext(value, base);
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
