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

char	player_char(t_map map, char test)
{
	if ((map.player == 1) && (test == 'o'))
		return (1);
	else if ((map.player == 2) && (test == 'x'))
		return (1);
	else
		return (0);
}

int 	line_fit(t_map map, int i, int j, int a)
{
	int 	b;
	int 	c;

	b = 0;
	c = 0;
	i = i + a;
	if (i >= map.h)
		return (-1);
	while (map.piece[a][b] != '\0')
	{
		if ((j + b) >= (int)ft_strlen(map.grid[a]))
		{
			return (-1);
		}
		else if (player_char(map, map.grid[i][j + b]) == 1)
		{
			if (player_char(map, map.piece[a][b]) == 1)
				c++;
		}
		else if (player_char(map, map.piece[a][b]) == 1)
		{
			if (map.grid[i][j + b] != '.')
				return (-1);
		}
		b++;
	}
	if ((c == 0) || (c == 1))
		return (c);
	return (-1);
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
		// fprintf(stderr, "\na == %d\n", a);
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

static int 	grader(t_map map, int i, int j)
{
	int 	grade;
	int		a;
	int 	b;

	grade = 0;
	a = 0;
	// fprintf(stderr, "\n\nentered grader\n\n");
	while (map.piece[a] != NULL)
	{
		b = 0;
		while (map.piece[a][b] != '\0')
		{
			grade += map.grade[i][j + b];
			b++;
		}
		a++;
		i++;
	}
	// fprintf(stderr, "\n\nleft grader\n\n");
	return (grade);
}

int		*solver(t_map map)
{
	int 	i;
	int		j;
	int 	*tmp;
	int 	res;

	i = 0;
	res = 0;
	tmp = (int *)malloc(sizeof(int) * 2);
	tmp[0] = 0;
	tmp[1] = 0;
	while (map.grid[i] != NULL)
	{
		j = 0;
		while (j < (int)ft_strlen(map.grid[i]))
		{
			if (can_fit(map, i, j) == 1)
			{
				//add result to list
				if ((tmp[0] == 0) && (tmp[1] == 0))
				{
					// fprintf(stderr, "\n\nentered\n\n");
					tmp[0] = i;
					tmp[1] = j;
					res++;
				}
				else
				{
					if (grader(map, i, j) > grader(map, tmp[0], tmp[1]))
					{
						//fprintf(stderr, "\n\ngrader overwrite, old tmp == [%d][%d], grader == %d\n\n", tmp[0], tmp[1], grader(map, tmp[0], tmp[1]));
						tmp[0] = i;
						tmp[1] = j;
						//fprintf(stderr, "\n\ngrader overwrite, new tmp == [%d][%d], grader == %d\n\n", i, j, grader(map, i, j));
						// return (tmp);
					}
					// else
					// {
						//fprintf(stderr, "\n\nno overwrite, old tmp == [%d][%d], grader == %d\n\n", tmp[0], tmp[1], grader(map, tmp[0], tmp[1]));
						//fprintf(stderr, "\n\nno overwrite, new tmp == [%d][%d], grader == %d\n\n", i, j, grader(map, i, j));
					// }
				}
			}
			j++;
		}
		i++;
	}
	if (res == 0)
	{
		tmp[0] = -1;
		tmp[1] = -1;
	}
	// fprintf(stderr, "\n\ndidn't segfault\n\n");
	return (tmp);
}
