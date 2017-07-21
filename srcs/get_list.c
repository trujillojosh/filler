/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 14:03:13 by jtrujill          #+#    #+#             */
/*   Updated: 2017/07/20 17:11:38 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			find_last_line(char *str)
{
	while ((ft_isdigit(*str) == 0) && (*str))
		str++;
	return (ft_atoi(str));
}

static int	find_j(int j, char *str)
{
	if (j == 1)
		return (1000);
	j--;
	if ((str[0] == 'P') && (str[1] == 'i'))
		j = find_last_line(str);
	return (j);
}

t_list		*get_list(void)
{
	char	*str;
	t_list	*head;
	t_list	*new;
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (get_next_line(0, &str) > 0)
	{
		if (i++ == 0)
		{
			new = ft_lstnew((void *)str, ft_strlen(str));
			head = new;
		}
		else
		{
			new->next = ft_lstnew((void *)str, ft_strlen(str));
			new = new->next;
		}
		if ((j = find_j(j, str)) == 1000)
			break ;
		ft_strdel(&str);
	}
	return (head);
}
