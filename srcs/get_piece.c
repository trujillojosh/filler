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

static char	**lst_to_piece(t_list *lst, int h)
{
	char	**piece;
	int 	i;

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
	ft_putstr_err("\n\npiece start\n\n");
	while (i < h)
	{
		ft_putstr_err(piece[i]);
		ft_putstr_err("\n");
		i++;
	}
	ft_putstr_err("\n\npiece end\n\n");
	return (piece);
}

char		**get_piece(t_list *lst)
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
	piece = lst_to_piece(lst, h);
	return (piece);
}
