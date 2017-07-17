/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 18:35:40 by jtrujill          #+#    #+#             */
/*   Updated: 2017/07/14 19:26:18 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		main(void)
{
	t_map		map;
	int 		*solve;
	// while (1)
	// {
		map = get_map();
		solve = solver(map);
		if (solve == NULL)
		{
			fprintf(stderr, "\n\n\n\nno fucking solution\n\n\n");
			return (0);
		}
		//solve[0] == y solve[1] == x
		//fprintf(stderr, "\n\nsx is %d, sy is %d\n\n", map.sx, map.sy);
		fprintf(stderr, "\n\nx == %d, y == %d\n\n", solve[1], solve[0]);
		//fprintf(stderr, "\n\nres is %d %d\n\n", (solve[1] - map.sx), (solve[0] - map.sy));
		//ft_printf("%d %d\n", (solve[1] - map.sx), (solve[0] - map.sy));
		ft_printf("%d %d\n", solve[1], solve[0]);
	// }
	//ft_putstr_err("hello\n");
	return (0);
}
