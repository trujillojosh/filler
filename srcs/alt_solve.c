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

// int 	line_fit(t_map map, int i, int j, int a)
// {
// 	int 	b;
// 	int 	c;

// 	b = 0;
// 	c = 0;
// 	while (b < (int)ft_strlen(map.piece[a]))
// 	{
// 		if ((j + b) >= (int)ft_strlen(map.grid[i]))
// 			return (-1);
// 		else if (map.piece[a][b] != '.')
// 		{
// 			if (map.grid[i][j + b] != '.')
// 				c++;
// 		}
// 		else
// 		{
// 			if (map.grid[i][j + b] != '.')
// 				return (-1);
// 		}
// 		b++;
// 	}
// 	return (c);
// }

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
			{
				c++;
			}
			// else
			// {
			// 	return (-1);
			// }
		}
		else if (player_char(map, map.piece[a][b]) == 1)
		{
			if (map.grid[i][j + b] != '.')
				return (-1);
		}
		b++;
	}
	// while (b < (int)ft_strlen(map.piece[a]))
	// {
	// 	if ((j + b) >= (int)ft_strlen(map.grid[i]))
	// 		return (-1);
	// 	else if (player_char(map, map.piece[a][b]) == 1)
	// 	{
	// 		if (player_char(map, map.grid[i][j + b]) == 1)
	// 			c++;
	// 	}
	// 	b++;
	// }
	if ((c == 0) || (c == 1))
		return (c);
	return (-1);
	//the idea here is to compare piece[a] to grid[i] to check for valid placement
	//Must have ONE and ONLY ONE match over all 4 pieces so should probably return connect
	//if any exist
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
int		*solver(t_map map)
{
	int 	i;
	int		j;

	i = 0;
	// fprintf(stderr, "\nentered solver\n");
	while (map.grid[i] != NULL)
	{
		j = 0;
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
			// else
			// 	fprintf(stderr, "no place on i == %d\n", i);
			//fprintf(stderr, "no on (%d, %d)\n", j, i);
			j++;
		}
		i++;
	}
	return (NULL);
}
