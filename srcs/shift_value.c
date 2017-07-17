/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 19:34:16 by jtrujill          #+#    #+#             */
/*   Updated: 2017/07/16 19:48:09 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int	shift_x(char **piece)
{
	int		i;
	int		j;
	int		r;

	i = 0;
	r = 1000;
	while (piece[i] != NULL)
	{
		j = 0;
		while (j < (int)ft_strlen(piece[i]))
		{
			if (piece[i][j] == 'o')
			{
				if ((j < r) || ((i == 0) && (r == -1)))
					r = j;
			}
			j++;
		}
		i++;
	}
	return (r);
}

static int	shift_y(char **piece)
{
	int		i;

	i = 0;
	while (piece[i] != NULL)
	{
		if (ft_char_count(piece[i], '*') > 0)
			return (i);
		i++;
	}
	return (-1);
}

int			shift_value(t_map map, int mode)
{
	if (mode == 0)
		return (shift_x(map.grid));
	else
		return (shift_y(map.piece));
}
