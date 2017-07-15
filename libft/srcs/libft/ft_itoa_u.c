/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 23:35:42 by jtrujill          #+#    #+#             */
/*   Updated: 2017/06/09 16:54:17 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static size_t	ft_u_len(unsigned int nb)
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

char			*ft_itoa_u(unsigned int n)
{
	size_t	i;
	char	*re;

	i = ft_u_len(n) - 1;
	if (!(re = (char *)malloc(sizeof(char) * ft_u_len(n) + 1)))
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
