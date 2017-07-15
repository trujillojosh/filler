/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 14:02:54 by jtrujill          #+#    #+#             */
/*   Updated: 2017/07/15 14:03:06 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static char			**lst_to_map(t_list *lst, int h)
{
	int		i;
	char	*temp;
	char 	**grid;

	i = 0;
	grid = (char **)malloc(sizeof(char *) * h);
	while (i < h)
	{
		temp = ft_strdup(lst->content);
		while ((*temp != '.') && (*temp != '\0'))
			temp++;
		grid[i] = ft_strdup(temp);
		// ft_strdel(&temp); //why the fuck does this break
		lst = lst->next;
		i++;
	}
	i = 0;
	ft_putstr_err("\n\nmap start\n\n");
	while (i < h)
	{
		ft_putstr_err(grid[i]);
		ft_putstr_err("\n");
		i++;
	}
	ft_putstr_err("\n\nmap end\n\n");
	return (grid);
}

char				**get_grid(t_list *lst)
{
	char	**grid;
	char	*tmp;
	int 	h;
	int		w;

	while (lst)
	{
		tmp = ft_strdup(lst->content);
		if ((tmp[0] == 'P') && (tmp[1] == 'l'))
			break ;
		ft_strdel(&tmp);
		lst = lst->next;
	}
	if (!tmp)
	{
		ft_strdel(&tmp);
		return (NULL);
	}
	while ((ft_isdigit(*tmp) == 0) && (*tmp != '\0'))
		tmp++;
	h = ft_atoi(tmp);
	while ((*tmp != ' ') && (*tmp != '\0'))
		tmp++;
	w = ft_atoi(tmp);
	lst = lst->next;
	lst = lst->next;
	grid = lst_to_map(lst, h);
	// fprintf(stderr, "\n\ntmp is %s\nh is %d, w is %d\n\n", tmp, h, w);
	return NULL;
}