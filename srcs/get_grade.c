/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_grade.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 23:34:20 by jtrujill          #+#    #+#             */
/*   Updated: 2017/07/20 17:15:32 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int	opp_piece(int player, char c)
{
	if ((player == 1) && (c == 'x'))
		return (1);
	else if ((player == 2) && (c == 'o'))
		return (1);
	else
		return (0);
}

static int	**helper(t_map map, int **res, int h)
{
	int		i;
	int		j;

	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < ((map.w) / 2))
		{
			if (res[h][j] < 5)
				res[h][j] = 2;
			j++;
		}
		i++;
	}
	return (res);
}

static int	**mark_edges(t_map map, int **res)
{
	int		i;
	int		j;
	int		h;

	i = 0;
	h = map.h / 2;
	if ((map.player == 1) && (map.h < 80))
	{
		while (h < map.h)
		{
			j = map.w / 2;
			while (j < map.w)
			{
				if (res[h][j] < 5)
					res[h][j] = 2;
				j++;
			}
			h++;
		}
	}
	else
		return (helper(map, res, h));
	return (res);
}

int			**get_grade(t_map map)
{
	int		i;
	int		j;
	int		**res;

	i = -1;
	res = (int **)malloc(sizeof(int *) * map.h);
	while (++i < map.h)
	{
		j = -1;
		res[i] = (int *)malloc(sizeof(int) * map.w);
		while (++j < map.w)
		{
			if (opp_piece(map.player, map.grid[i][j]) == 1)
			{
				if ((j + 1) < map.w)
					res[i][j + 1] = 5;
				if (j != 0)
					res[i][j - 1] = 5;
				if (i != 0)
					res[i - 1][j] = 5;
			}
			res[i][j] = 0;
		}
	}
	return (mark_edges(map, res));
}
