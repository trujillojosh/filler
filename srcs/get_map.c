/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 22:00:20 by jtrujill          #+#    #+#             */
/*   Updated: 2017/07/20 17:14:56 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int	get_dimensions(t_list *lst, int opt)
{
	char	*tmp;
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
	return (h);
}

static int	get_player(t_list *lst)
{
	char		*tmp;
	static int	i = 0;
	static int	j = 0;

	if (j > 0)
		return (i);
	j++;
	while (lst)
	{
		tmp = ft_strdup(lst->content);
		if ((tmp[0] == '$') && (tmp[1] == '$') && (tmp[2] == '$'))
			break ;
		ft_strdel(&tmp);
		lst = lst->next;
	}
	while (*tmp != '\0')
	{
		if ((*tmp == '1') || (*tmp == '2'))
			break ;
		tmp++;
	}
	if (!tmp)
		return (0);
	i = *tmp == '1' ? 1 : 2;
	return (i);
}

t_map		get_map(void)
{
	t_map		map;
	t_list		*lst;
	static int	player = 0;

	lst = get_list();
	map.h = get_dimensions(lst, 1);
	map.w = get_dimensions(lst, 2);
	if (player == 0)
		player = get_player(lst);
	map.player = player;
	map.grid = get_grid(lst);
	map.init_piece = init_piece(lst, map);
	map.sx = shift_value(map, 0);
	map.sy = shift_value(map, 1);
	map.grade = get_grade(map);
	map.piece = get_piece(map);
	return (map);
}
