/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 21:25:53 by jtrujill          #+#    #+#             */
/*   Updated: 2017/07/16 22:08:25 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int 	check(char c, int player)
{
	if ((c == 'o') || (c == 'x'))
	{
		if (player == 0)
			return (1);
		else if ((player == 1) && (c == 'o'))
			return (1);
		else if ((player == 2) && (c == 'x'))
			return (1);
	}
	return (0);
}

static int	fit_line(t_map map, int i, int j, int a)
{
	int 	b;
	int 	connect;
	
	b = 0;
	connect = 0;
	while (b < (int)ft_strlen(map.place[a]))
	{
		if (check(map.place[a][b], 0) == 1)
		{
			if ((j + b) < map.w)
			{
				if (check(map.grid[i][j + b], map.player) == 1)
					connect++;
				else if (map.grid[i][j + b] != '.')
					return (-1);
			}
			else
				return (-1);
		}
		b++;
	}
	if (connect <= 1)
		return (connect);
	return (-1);
}

static int 	can_fit(t_map map, int i, int j)
{
	int 	connect;
	// int 	pcs;
	int 	a;

	a = 0;
	// pcs = ft_char_count(map.place);
	connect = 0;
	while (map.place[a] != NULL)
	{
		if (fit_line(map, i, j, a) >= 0)
		{
			connect += fit_line(map, i, j, a);
			if (connect > 1)
				return (-1);
		}
		a++;
	}
	if (connect == 1)
		return (1);
	return (-1);
}

int		*solver(t_map map)
{
	int 	i;
	int		j;

	i = 0;
	while (map.grid[i] != NULL)
	{
		j = 0;
		while (j < (int)ft_strlen(map.grid[i]))
		{
			if (can_fit(map, i, j) == 1)
			{
				//add result to list
				int *tmp = (int *)malloc(sizeof(int) * 2);
				tmp[0] = i;
				tmp[1] = j;
				return (tmp);
			}
			// else
			// 	fprintf(stderr, "no place on i == %d\n", i);
			j++;
		}
		i++;
	}
	return (NULL);
}

