/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 17:26:45 by jtrujill          #+#    #+#             */
/*   Updated: 2017/07/20 17:41:09 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_list		*ft_lstend(t_list *head, char *new)
{
	t_list	*curr;

	curr = head;
	while (head)
	{
		head = head->next;
	}
	head->next = ft_lstnew((void *)new, ft_strlen(new));
	return (curr);
}
