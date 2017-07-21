/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_assets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 15:23:46 by jtrujill          #+#    #+#             */
/*   Updated: 2017/07/20 17:16:06 by jtrujill         ###   ########.fr       */
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

int		line_fit(t_map map, int i, int j, int a)
{
	int		b;
	int		c;

	b = 0;
	c = 0;
	i = i + a;
	if (i >= map.h)
		return (-1);
	while (map.piece[a][b] != '\0')
	{
		if ((j + b) >= (int)ft_strlen(map.grid[a]))
			return (-1);
		else if (player_char(map, map.grid[i][j + b]) == 1)
		{
			if (player_char(map, map.piece[a][b]) == 1)
				c++;
		}
		else if (player_char(map, map.piece[a][b]) == 1)
			if (map.grid[i][j + b] != '.')
				return (-1);
		b++;
	}
	if ((c == 0) || (c == 1))
		return (c);
	return (-1);
}

int		can_fit(t_map map, int i, int j)
{
	int		a;
	int		b;
	int		c;

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
