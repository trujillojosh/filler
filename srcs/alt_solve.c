/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alt_solve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 23:35:59 by jtrujill          #+#    #+#             */
/*   Updated: 2017/07/16 23:36:13 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int 	line_fit(t_map map, int i, int j, int a)
{
	int 	b;
	int 	c;

	b = 0;
	c = 0;
	while (b < (int)ft_strlen(map.piece[a]))
	{
		if ((j + b) >= (int)ft_strlen(map.grid[i]))
			return (-1);
		else if (map.piece[a][b] != '.')
		{
			if (map.grid[i][j + b] != '.')
				c++;
		}
		else
		{
			if (map.grid[i][j + b] != '.')
				return (-1);
		}
		b++;
	}
	return (c);
}

int		can_fit(t_map map, int i, int j)
{
	int 	a;
	int 	b;
	int 	c;

	a = 0;
	b = 0;
	c = 0;
	while (map.piece[a] != NULL)
	{
		if (c > 1)
			return (-1);
		if (line_fit(map, i, j, a) >= 0)
			c += line_fit(map, i, j, a);
		else
			return (-1);
		a++;
	}
	if (c == 1)
		return (1);
	else
		return (-1);
}
int		*solver(t_map map)
{
	int 	i;
	int		j;

	i = 0;
	while (map.grid[i] != NULL)
	{
		j = map.sx;
		// fprintf(stderr, "\n\nfucking i == %d\n", i);
		while (j < (int)ft_strlen(map.grid[i]))
		{
			// fprintf(stderr, "	fucking j == %d\n", j);
			if (can_fit(map, i, j) == 1)
			{
				//add result to list
				int *tmp = (int *)malloc(sizeof(int) * 2);
				tmp[0] = i;
				tmp[1] = j;
				return (tmp);
			}
			else if ((i == 3) && (j == 3))
				fprintf(stderr, "\n\nfailed on 3, 3\n\n");
			// else
			// 	fprintf(stderr, "no place on i == %d\n", i);
			//fprintf(stderr, "no on (%d, %d)\n", j, i);
			j++;
		}
		i++;
	}
	return (NULL);
}
