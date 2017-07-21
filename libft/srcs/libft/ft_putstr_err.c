/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_err.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 18:17:38 by jtrujill          #+#    #+#             */
/*   Updated: 2017/07/14 18:51:36 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void	helper_p1(char s)
{
	write(2, "\x1b[31m", 5);
	write(2, &s, 1);
	write(2, "\x1b[0m", 4);
}

static void	helper_p2(char s)
{
	write(2, "\x1b[33m", 5);
	write(2, &s, 1);
	write(2, "\x1b[0m", 4);
}

void		ft_putstr_err(char const *s)
{
	int		i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		if (s[i] == 'o')
			helper_p1(s[i]);
		else if (s[i] == 'x')
			helper_p2(s[i]);
		else
			write(2, &s[i], 1);
		i++;
	}
}
