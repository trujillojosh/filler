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

// void		print_2d_err(int **res, t_map map)
// {
// 	int		i;
// 	int		j;

// 	i = 0;
// 	// fprintf(stderr, "\n\n2d arr print\n\n");
// 	while (i < map.h)
// 	{
// 		j = 0;
// 		while (j < map.w)
// 		{
// 			// fprintf(stderr, "%d ", res[i][j]);
// 			j++;
// 		}
// 		// fprintf(stderr, "\n");
// 		i++;
// 	}
// 	// fprintf(stderr, "\n\nended 2d arr print\n\n");
// }

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
			res[i][j] = 0;
			j++;
		}
	i++;
	}
	// print_2d_err(res, map);
	return (res);
}
