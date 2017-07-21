/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 15:50:19 by jtrujill          #+#    #+#             */
/*   Updated: 2017/07/20 17:13:10 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static char	*get_row(char *in, t_map map)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = map.sx[0];
	res = ft_strnew(map.sx[1] - map.sx[0] + 2);
	while (i < (map.sx[1] - map.sx[0] + 1))
	{
		res[i] = in[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}

char		**get_piece(t_map map)
{
	int		i;
	int		k;
	char	**res;

	res = (char **)malloc(sizeof(char *) * (map.sy[1] - map.sy[0] + 2));
	i = 0;
	k = map.sy[0];
	while (i < (map.sy[1] - map.sy[0] + 1))
	{
		res[i] = get_row(map.init_piece[k], map);
		i++;
		k++;
	}
	res[i] = NULL;
	return (res);
}
