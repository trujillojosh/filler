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

static int	get_dimensions(t_list *lst, int opt)
{
	char 	*tmp;
	int		h;
	
	while (lst)
	{
		tmp = ft_strdup(lst->content);
		if ((tmp[0] == 'P') && (tmp[1] == 'l'))
			break ;
		ft_strdel(&tmp);
		lst = lst->next;
	}
	if (!tmp)
		return (0);
	while ((ft_isdigit(*tmp) == 0) && (*tmp != '\0'))
		tmp++;
	if (opt == 1)
		h = ft_atoi(tmp);
	else
	{
		while (*tmp != ' ')
			tmp++;
		tmp++;
		h = ft_atoi(tmp);
	}
	// ft_putstr_err("\n\n h == ");
	// ft_putstr_err(ft_itoa(h));
	// ft_putstr_err("\n\n");
	return (h);
}

static int	get_player(t_list *lst)
{
	char	*tmp;
	int 	i;

	i = 0;
	while (lst)
	{
		tmp = ft_strdup(lst->content);
		if ((tmp[0] == '$') && (tmp[1] == '$') && (tmp[2] == '$'))
			break ;
		ft_strdel(&tmp);
		lst = lst->next;
	}
	if (!tmp)
		return (0);
	while (*tmp != '\0')
	{
		if ((*tmp == '1') || (*tmp == '2'))
			break ;
		tmp++;
	}
	if (!tmp)
		return (0);
	i = *tmp == '1' ? 1 : 2;
	// ft_putstr_err("\n\n i == ");
	// ft_putstr_err(ft_itoa(i));
	// ft_putstr_err("\n\n");
	return (i);
}

// void		print_lst_error(t_list *list)
// {
// 	while (list)
// 	{
// 		ft_putstr_err(list->content);
// 		ft_putstr_err("\n");
// 		list = list->next;
// 	}
// }

t_map			get_map(void)
{
	t_map		map;
	t_list		*lst;

	lst = get_list();
	map.h = get_dimensions(lst, 1);
	map.w = get_dimensions(lst, 2);
	map.player = get_player(lst);
	map.grid = get_grid(lst);
	map.piece = get_piece(lst);
	map.sx = shift_value(map, 0);
	map.sy = shift_value(map, 1);
	map.grade = get_grade(map);
	map.place = get_place(map);
	fprintf(stderr, "\n\nmap stats\nh == %d, w == %d\n\n", map.h, map.w);
	// print_lst_error(lst);
	return (map);
}