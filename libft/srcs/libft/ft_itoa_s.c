/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 21:35:43 by jtrujill          #+#    #+#             */
/*   Updated: 2017/06/10 18:44:40 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static size_t	ft_s_len(short nb)
{
	size_t		i;

	i = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		i++;
	}
	while ((nb / 10) != 0)
	{
		i++;
		nb = nb / 10;
	}
	i++;
	return (i);
}

char			*ft_itoa_s(short n)
{
	size_t	i;
	char	*re;

	i = ft_s_len(n) - 1;
	if (!(re = (char *)malloc(sizeof(char) * ft_s_len(n) + 1)))
		return (NULL);
	re[i + 1] = '\0';
	if (n < 0)
	{
		re[0] = '-';
		n = n * -1;
	}
	while (n > 9)
	{
		re[i] = (n % 10) + '0';
		i--;
		n = n / 10;
	}
	if (n >= 0 && n <= 9)
		re[i] = n + '0';
	return (re);
}
