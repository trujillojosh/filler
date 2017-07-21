/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 15:26:55 by jtrujill          #+#    #+#             */
/*   Updated: 2017/07/20 17:08:03 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int	grader(t_map map, int i, int j)
{
	int		grade;
	int		a;
	int		b;

	grade = 0;
	a = 0;
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
	return (grade);
}

static int	*arr_setup(void)
{
	int		*res;

	res = (int *)malloc(sizeof(int) * 2);
	res[0] = 0;
	res[1] = 0;
	return (res);
}

static int	*arr_final(int *input, int res)
{
	if (res == 0)
	{
		input[0] = -1;
		input[1] = -1;
	}
	return (input);
}

static int	*arr_modify(int *input, int i, int j, t_map map)
{
	if ((input[0] == 0) && (input[1] == 0))
	{
		input[0] = i;
		input[1] = j;
	}
	else if (grader(map, i, j) > grader(map, input[0], input[1]))
	{
		input[0] = i;
		input[1] = j;
	}
	return (input);
}

int			*solver(t_map map)
{
	int		i;
	int		j;
	int		*tmp;
	int		res;

	i = 0;
	res = 0;
	tmp = arr_setup();
	while (map.grid[i] != NULL)
	{
		j = 0;
		while (j < (int)ft_strlen(map.grid[i]))
		{
			if (can_fit(map, i, j) == 1)
			{
				tmp = arr_modify(tmp, i, j, map);
				res++;
			}
			j++;
		}
		i++;
	}
	return (arr_final(tmp, res));
}
