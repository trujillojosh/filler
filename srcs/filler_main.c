/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 18:35:40 by jtrujill          #+#    #+#             */
/*   Updated: 2017/07/20 17:10:38 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		main(void)
{
	t_map		map;
	int			*solve;

	while (1)
	{
		map = get_map();
		solve = solver(map);
		if ((solve[0] == -1) && (solve[1] == -1))
			ft_printf("%d %d\n", 0, 0);
		else
			ft_printf("%d %d\n", (solve[0] - map.sy[0]),
				(solve[1] - map.sx[0]));
		free(map.grid);
		free(map.init_piece);
		free(map.piece);
		free(map.grade);
		free(map.sx);
		free(map.sy);
		if ((solve[0] == -1) && (solve[1] == -1))
			return (0);
		free(solve);
	}
	return (0);
}
