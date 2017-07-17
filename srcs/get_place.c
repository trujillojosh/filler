/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_place.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 20:47:58 by jtrujill          #+#    #+#             */
/*   Updated: 2017/07/16 20:50:40 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

char		*convert(t_map map, char *input)
{
	char 	c;
	int		i;
	char 	*res;
	i = 0;
	c = map.player == 1 ? 'o' : 'x';
	res = (char *)malloc(sizeof(char) * (ft_strlen(input) + 1));
	while (i < (int)ft_strlen(input))
	{
		if (input[i] == '*')
			res[i] = c;
		else
			res[i] = input[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
char		**get_place(t_map map)
{
	char 	**res;
	int 	x;
	int 	y;
	int 	i;
	int 	j;

	j = 0;
	i = 0;
	x = map.sx;
	y = map.sy;
	while (map.piece[i] != NULL)
		i++;
	res = (char **)malloc(sizeof(char *) * ((i - y) + 1));
	while (map.piece[y] != NULL)
	{
		//fprintf(stderr, "\n\nshift value is: %d", y);
		res[j] = convert(map, &(map.piece[y][x]));
		j++;
		y++;
	}
	res[j] = NULL;
	// fprintf(stderr, "\n\nshifted piece is: \n");
	// i = 0;
	// while (i < j)
	// {

	// 	fprintf(stderr, "%s\n", res[i]);
	// 	i++;
	// }
	return (res);
}