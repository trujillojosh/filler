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

static int	*shift_x(char **piece)
{
	int			i;
	int			j;
	int			*res;

	i = 0;
	res = (int *)malloc(sizeof(int) * 2);
	res[0] = -1;
	res[1] = -1;
	while (piece[i] != NULL)
	{
		j = 0;
		while (j < (int)ft_strlen(piece[i]))
		{
			if ((piece[i][j] == 'o') || (piece[i][j] == 'x'))
			{
				if ((res[0] == -1) || (j < res[0]))
					res[0] = j;
				if ((res[0] == -1) || (j > res[1]))
					res[1] = j;
			}
			j++;
		}
		i++;
	}
	return (res);
}

static int	*shift_y(char **piece)
{
	int		*res;
	int		i;

	i = 0;
	res = (int *)malloc(sizeof(int) * 2);
	res[0] = -1;
	res[1] = -1;
	while (piece[i] != NULL)
	{
		if ((ft_char_count(piece[i], 'o') > 0) ||
			(ft_char_count(piece[i], 'x') > 0))
		{
			if ((res[0] == -1) || (i < res[0]))
				res[0] = i;
			if ((res[0] == -1) || (i > res[1]))
				res[1] = i;
		}
		i++;
	}
	return (res);
}

int			*shift_value(t_map map, int mode)
{
	if (mode == 0)
		return (shift_x(map.init_piece));
	else
		return (shift_y(map.init_piece));
}
