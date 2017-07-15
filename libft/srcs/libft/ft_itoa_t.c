/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_t.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 19:36:18 by jtrujill          #+#    #+#             */
/*   Updated: 2017/06/10 18:45:19 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static size_t	ft_t_len(size_t nb)
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

char			*ft_itoa_t(size_t n)
{
	size_t	i;
	char	*re;

	i = ft_t_len(n) - 1;
	if (!(re = (char *)malloc(sizeof(char) * ft_t_len(n) + 1)))
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
