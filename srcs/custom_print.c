/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 14:45:06 by jtrujill          #+#    #+#             */
/*   Updated: 2017/07/20 17:12:13 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void			print_piece(char **piece, int h)
{
	int		i;

	i = 0;
	ft_putstr_err("\n\nGiven Piece:\n\n");
	while (i < h)
	{
		ft_putstr_err(piece[i]);
		ft_putstr_err("\n");
		i++;
	}
	ft_putstr_err("\n\n\n");
}

static void		grid_help(char **grid)
{
	int		b;
	int		i;

	i = 0;
	b = (int)ft_strlen(grid[0]);
	b = (b - 7) / 2;
	while ((i - 1) <= (int)ft_strlen(grid[0]))
	{
		ft_putstr_err("_");
		i++;
	}
	ft_putstr_err("\n");
	while (b--)
		ft_putstr_err(" ");
	ft_putstr_err("Given Map\n");
	i = 0;
	while ((i - 1) <= (int)ft_strlen(grid[0]))
	{
		ft_putstr_err("_");
		i++;
	}
	ft_putstr_err("\n");
}

void			print_grid(char **grid, int h)
{
	int		i;

	i = 0;
	grid_help(grid);
	while (i < h)
	{
		ft_putstr_err("|");
		ft_putstr_err(grid[i]);
		ft_putstr_err("|");
		ft_putstr_err("\n");
		i++;
	}
	i = 0;
	while ((i - 1) <= (int)ft_strlen(grid[0]))
	{
		ft_putstr_err("_");
		i++;
	}
	ft_putstr_err("\n\n\n");
}
