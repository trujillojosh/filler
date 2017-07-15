/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ull.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 21:37:34 by jtrujill          #+#    #+#             */
/*   Updated: 2017/06/10 18:45:59 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static size_t	ft_ull_len(unsigned long long nb)
{
	size_t		i;

	i = 0;
	while ((nb / 10) != 0)
	{
		i++;
		nb = nb / 10;
	}
	i++;
	return (i);
}

char			*ft_itoa_ull(unsigned long long n)
{
	size_t	i;
	char	*re;

	i = ft_ull_len(n) - 1;
	if (!(re = (char *)malloc(sizeof(char) * ft_ull_len(n) + 1)))
		return (NULL);
	re[i + 1] = '\0';
	while (n > 9)
	{
		re[i] = (n % 10) + '0';
		i--;
		n = n / 10;
	}
	if (n <= 9)
		re[i] = n + '0';
	return (re);
}
