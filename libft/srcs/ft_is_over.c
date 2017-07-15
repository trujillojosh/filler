/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_over.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 16:32:33 by jtrujill          #+#    #+#             */
/*   Updated: 2017/06/10 17:07:48 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_is_over(char c, int mode)
{
	char		valid[16];
	static int	count = 0;

	ft_strcpy(valid, "sSpdDioOuUxXcC%");
	if (count == -1)
	{
		count = 0;
		return (0);
	}
	else if ((count == 0) && (mode != 2))
		count++;
	else if ((ft_char_count(valid, c) != 0) || (c == '\0'))
	{
		if (c == '\0')
		{
			count = 0;
			return (0);
		}
		else
			count = -1;
	}
	return (1);
}
