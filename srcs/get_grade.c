/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_grade.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 23:34:20 by jtrujill          #+#    #+#             */
/*   Updated: 2017/07/16 00:34:02 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

//Ideas on how to grade placement?
//Grade top/bottom of map better depending on opposite corner
//Give a boost to cutoff points

static int	opp_piece(int player, char c)
{
	if ((player == 1) && (c == 'x'))
		return (1);
	else if ((player == 2) && (c == 'o'))
		return (1);
	else
		return (0);
}

int			**get_grade(t_map map)
{
	int		i;
	int 	j;
	int 	**res;
	
	i = 0;
	res = (int **)malloc(sizeof(int *) * map.h);
	while (i < map.h)
	{
		j = 0;
		res[i] = (int *)malloc(sizeof(int) * map.w);
		while (j < map.w)
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
			j++;
		}
	i++;
	}
	// i = 0;
	// while(i < map.h)
	// {
	// 	j = 0;
	// 	while (j < map.w)
	// 	{
	// 		fprintf(stderr, "%d ", res[i][j]);
	// 		j++;
	// 	}
	// 	i++;
	// 	fprintf(stderr, "\n");
	// }
	return (res);
}
