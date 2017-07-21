/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 15:32:33 by jtrujill          #+#    #+#             */
/*   Updated: 2017/07/20 17:19:15 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/ft_printf.h"

typedef	struct			s_map
{
	char				**grid;
	char				**piece;
	int					**grade;
	int					player;
	int					h;
	int					w;
	int					sx;
	int					sy;

}						t_map;

int						filler_main(void);
t_map					get_map(void);
char					**get_grid(t_list *lst);
t_list					*get_list(void);
char					**get_piece(t_list *lst, t_map map);
int						**get_grade(t_map map);
int						shift_value(t_map map, int mode);
char					**get_place(t_map map);
int						*solver(t_map map);
void					print_piece(char **piece, int h);
void					print_grid(char **piece, int h);
char					player_char(t_map map, char test);
int						line_fit(t_map map, int i, int j, int a);
int						can_fit(t_map map, int i, int j);

#endif
