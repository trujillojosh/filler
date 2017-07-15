/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 22:00:20 by jtrujill          #+#    #+#             */
/*   Updated: 2017/07/14 22:00:46 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		print_lst_error(t_list *list)
{
	while (list)
	{
		ft_putstr_err(list->content);
		ft_putstr_err("\n");
		list = list->next;
	}
}

t_map			get_map(void)
{
	t_map		map;
	t_list		*lst;

	lst = get_list();
	map.grid = get_grid(lst);
	print_lst_error(lst);
	return (map);
}