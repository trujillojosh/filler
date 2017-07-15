/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_todo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 15:06:21 by jtrujill          #+#    #+#             */
/*   Updated: 2017/06/09 16:28:33 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_remove_todo(char *todo, char *remove)
{
	char	*res;
	int		i;
	int		j;

	j = 0;
	i = ft_strlen(todo) - 1;
	res = ft_strnew(ft_strlen(todo) - ft_strlen(remove));
	while (todo[i] != remove[0])
		i--;
	while (i > j)
	{
		res[j] = todo[j];
		j++;
	}
	i += ft_strlen(remove);
	while ((todo[i] != '\0') && (i < (int)ft_strlen(todo)))
	{
		res[j] = todo[i];
		j++;
		i++;
	}
	if (res)
		return (res);
	return (NULL);
}
