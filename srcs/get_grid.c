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

static char 		*lowercase(char *input)
{
	int		i;
	char 	*res;

	i = 0;
	//fprintf(stderr, "\nlower is    %s\n", input);
	res = ft_strdup(input);
	while (res[i] != '\0')
	{
		if ((res[i] == 'O') || (res[i] == 'X'))
			res[i] = ft_tolower(res[i]);
		i++;
	}
	return (res);
}

static char			**lst_to_map(t_list *lst, int h)
{
	int		i;
	char	*temp;
	char 	**grid;

	i = 0;
	grid = (char **)malloc(sizeof(char *) * (h + 1));
	while (i < h)
	{
		temp = ft_strdup(lst->content);
		//fprintf(stderr, "\ntemp is %s\n", temp);
		while ((*temp != ' ') && (*temp != '\0'))
			temp++;
		temp++;
		grid[i] = lowercase(temp);
		//fprintf(stderr, "\ngrid[i] is %s\n", temp);
		// ft_strdel(&temp); //why the fuck does this break
		lst = lst->next;
		i++;
	}
	grid[i] = NULL;
	// i = 0;
	// ft_putstr_err("\n\nmap start\n\n");
	// while (i < h)
	// {
	// 	ft_putstr_err(grid[i]);
	// 	ft_putstr_err("\n");
	// 	i++;
	// }
	// ft_putstr_err("\n\nmap end\n\n");
	return (grid);
}

char				**get_grid(t_list *lst)
{
	char	**grid;
	char	*tmp;
	int 	h;

	while (lst)
	{
		tmp = ft_strdup(lst->content);
		if ((tmp[0] == 'P') && (tmp[1] == 'l'))
			break ;
		ft_strdel(&tmp);
		lst = lst->next;
	}
	if (!tmp)
		return (NULL);
	while ((ft_isdigit(*tmp) == 0) && (*tmp != '\0'))
		tmp++;
	h = ft_atoi(tmp);
	lst = lst->next;
	lst = lst->next;
	grid = lst_to_map(lst, h);
	return (grid);
}