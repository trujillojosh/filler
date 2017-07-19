/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 15:50:19 by jtrujill          #+#    #+#             */
/*   Updated: 2017/07/15 16:56:36 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static char	**lst_to_piece(t_list *lst, t_map map, int h)
{
	char	**piece;
	int 	i;
	int 	j;
	char 	c;
	
	c = map.player == 1 ? 'o' : 'x';
	i = 0;
	piece = (char **)malloc(sizeof(char *) * (h + 1));
	while (i < h)
	{
		piece[i] = ft_strdup(lst->content);
		lst = lst->next;
		i++;
	}
	piece[i] = NULL;
	i = 0;
	while (i < h)
	{
		j = 0;
		while (piece[i][j] != '\0')
		{
			if (piece[i][j] == '*')
				piece[i][j] = c;
			j++;
		}
		i++;
	}
	i = 0;
	// ft_putstr_err("\n\npiece start\n\n");
	// while (i < h)
	// {
	// 	ft_putstr_err(piece[i]);
	// 	ft_putstr_err("\n");
	// 	i++;
	// }
	// ft_putstr_err("\n\npiece end\n\n");
	return (piece);
}

char		**get_piece(t_list *lst, t_map map)
{
	char	**piece;
	char	*tmp;
	int		h;
	
	while (lst)
	{
		tmp = ft_strdup(lst->content);
		if ((tmp[0] == 'P') && (tmp[1] == 'i'))
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
	piece = lst_to_piece(lst, map, h);
	return (piece);
}
